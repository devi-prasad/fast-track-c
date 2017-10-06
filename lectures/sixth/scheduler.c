#define _GNU_SOURCE

#include "scheduler.h"

int32_t count_days(char const *ymdbegin, char const *ymdend)
{
    int8_t days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int32_t sy = 0, sm = 0, sd = 0, ey = 0, em = 0, ed = 0;

    sscanf(ymdbegin, "%d-%d-%d", &sy, &sm, &sd);
    sscanf(ymdend, "%d-%d-%d", &ey, &em, &ed);

    if (ey > 2018) {
        /*printf("Schedules allowed only upto 2018-December-31\n");*/
        return 0;
    }
    
    if (sy < 2017 || sy > 2018) return 0;
    if (ey < sy || ey > 2018) return 0;
    if (sm < 1 || sm > 12 || em < 1 || em > 12) return 0;

    if (sd < 1 || sd > days[sm - 1]) return 0;

    if (ed < 1 || ed > days[em - 1]) return 0;

    int32_t days_count = 0;
    if (sy < ey) {
        days_count = count_days(ymdbegin, "2017-12-31");
        days_count += count_days("2018-01-01", ymdend);
        return days_count;
    }

    if (sy == ey) {
        if (em == sm) {
            days_count = ed - sd + 1;
        } else if (em > sm) {
            days_count = (days[sm - 1] - sd) + 1;
            for (int32_t m = sm + 1; m < em; ++m) {
                days_count += days[m - 1];
            }
            days_count += ed;
        }
    }

    return days_count;
}

/**
 * Correctly computes the next day taking into consideration the year, month
 * and days in a month.
 */
int32_t next_ymd(int32_t cy, int32_t cm, int32_t cd,
                 int32_t *ny, int32_t *nm, int32_t *nd)
{
    int8_t days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    *ny = *nm = *nd = 0;
    if (cy < 2017 || cy > 2019) return 0;
    if (cm < 1 || cm > 12) return 0;
    int32_t last_day_of_month = days[cm - 1];
    if (cd < 1 || cd > last_day_of_month) return 0;

    *ny = cy; *nm = cm; *nd = cd;
    if (cm == 12 && cd == 31) {
        *ny = ++cy;
        *nm = 1;
        *nd = 1;
    } else if (cm < 12 && cd == last_day_of_month) {
        *nm = ++cm;
        *nd = 1;
    } else if (cm < 12 && cd < last_day_of_month) {
        *nd = ++cd;
    }

    //assert(*ny <= 2020 && *nm >= 1 && *nm <= 12);
    //assert(*nd >= 1 && *nd <= days[*nm - 1]);

    return 1;
}

int32_t next_month(int32_t cy, int32_t cm, int32_t *ny, int32_t *nm)
{
    *ny = *nm = 0;
    if (cy < 2017 || cy > 2019) return 0;
    if (cm < 1 || cm > 12) return 0;

    *ny = cy; *nm = cm;
    if (cm == 12) {
        *ny = ++cy;
        *nm = 1;
    } else if (cm < 12) {
        *nm = ++cm;
    }

    assert(*ny <= 2020 && *nm >= 1 && *nm <= 12);
    return 1;
}

int32_t next_week(int32_t cy, int32_t cm, int32_t cd,
                  int32_t *ny, int32_t *nm, int32_t *nd)
{
    int8_t days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    *ny = *nm = *nd = 0;
    if (cy < 2017 || cy > 2019) return 0;
    if (cm < 1 || cm > 12) return 0;
    int32_t last_day_of_month = days[cm - 1];
    if (cd < 1 || cd > last_day_of_month) return 0;

    *ny = cy; *nm = cm; *nd = cd;

    int32_t next_week_day = cd + 7;
    if (next_week_day <= last_day_of_month) {
        *nd = next_week_day;
    } else { /* we are moving into a new month and perhaps a new year! */
        next_week_day -= last_day_of_month;
        if (cm == 12) {
            *ny = ++cy;
            *nm = 1;
            *nd = next_week_day;
        } else if (cm < 12) {
            *nm = ++cm;
            *nd = next_week_day;
        }
    }

    assert(*ny <= 2020 && *nm >= 1 && *nm <= 12);
    //assert(*nd >= 1 && *nd <= days[*nm - 1]);

    return 1;
}

/**
 * 'duration' is in minutes. Assumes less than 24 hours.
 *      0 <= duration < (60 * 24)
 * 'start_date_time' is in 'yyyy-mm-dd hh:mm' format.
 * 'end_date' is in 'yyyy-mm-dd' format,
 * 'end_time_str' is the output argument. It will be in 'hh:mm' format.
 *     6 <= length(end_time_str)
 * computes the correct end time for the given arguments.
 */
void compute_end_time(int32_t duration,
                      char const *start_datetime,
                      char *end_time_str /* out */)
{
    int8_t duration_hrs  = duration / 60;
    int8_t duration_mins = duration % 60;

    char start_date_str[11], start_time_str[6];
    int32_t start_hr, start_mins;
    int32_t end_hr, end_mins;

    sscanf(start_datetime, "%s%s", start_date_str, start_time_str);
    sscanf(start_time_str, "%d:%d", &start_hr, &start_mins);

    end_hr   = start_hr + duration_hrs;
    end_mins = start_mins + duration_mins;
    if (end_mins >= 60) {
        end_mins -= 60;
        ++end_hr;
    }

    char *fmt   = (end_hr < 10) ? "0%d:" : "%d:";
    sprintf(end_time_str, fmt, end_hr);
    fmt = (end_mins < 10) ? "0%d" : "%d";
    sprintf(end_time_str+3, fmt, end_mins);
}

/**
 * returns the current date and time in 'yyyy-mm-dd' format.
 * This solution is portable across Linux and POSIX flavors.
 * Assumes sizeof(dtstr) >= 11
 * Returns the value of the pointer 'dtstr'.
 */
char *get_local_datetime_str(char *dtstr)
{
    time_t now = time(NULL);
    strftime(dtstr, 11, "%Y-%m-%d", localtime(&now));
    return dtstr;
}
