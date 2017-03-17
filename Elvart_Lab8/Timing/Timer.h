
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#ifndef TIMER_H
#define TIMER_H

class Timer
{
  public:
    void start();
    double stop();
    void printTime(double duration);

  private:
    timeval startTime;
    timeval endTime;
};

#endif
