
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/signal.h>
#include <assert.h>

struct _signal_system_ {
    unsigned char yellow_interval;
    unsigned char min_green;
    unsigned char max_green;
    unsigned int  red_time;
    unsigned char cycle_time; /* The time taken to complete one cycle */
};

typedef struct _signal_system_ SignalSystem;

static SignalSystem sigsys;

void transition(int sn)
{
    alarm()
}


int main()
{
  signal(SIGALRM, alarm_handler);
  alarm(1);
  
  return 0;
}
