#include "scheduler.h"

int32_t main(int32_t argc, char **argv)
{
	int32_t ndays = 0;

	ndays = count_days("2017-1006", "2017-10-06");
    assert(ndays == 0);

    return 0;
}