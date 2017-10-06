#ifndef SCHEDULER_INCLUDED
#define SCHEDULER_INCLUDED
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <assert.h>

int32_t count_days(char const *ymdbegin, char const *ymdend);

int32_t next_ymd(int32_t cy, int32_t cm, int32_t cd,
                 int32_t *ny, int32_t *nm, int32_t *nd);

int32_t next_month(int32_t cy, int32_t cm, int32_t *ny, int32_t *nm);

int32_t next_week(int32_t cy, int32_t cm, int32_t cd,
                  int32_t *ny, int32_t *nm, int32_t *nd);

void compute_end_time(int32_t duration,
                      char const *start_datetime,
                      char *end_time_str /* out */);

char *get_local_datetime_str(char *dtstr);

#endif