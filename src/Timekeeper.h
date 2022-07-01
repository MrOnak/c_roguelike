#ifndef TIMEKEEPER_H
#define TIMEKEEPER_H

#include <stdlib.h>

#include "Life.h"


struct living_beings {
  Life * being;
  struct living_beings * next;
  struct living_beings * prev;
};


class Timekeeper {
  private:
    long currentTime;
    living_beings * actors;
    living_beings * last;

  public:
    Timekeeper();
    void step();
    long getTime();
    bool registerObject(Life& o);
};

#endif
