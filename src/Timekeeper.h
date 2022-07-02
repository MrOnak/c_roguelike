#ifndef TIMEKEEPER_H
#define TIMEKEEPER_H

#include <stdlib.h>
#include <unistd.h>
#include <typeinfo>

#include "Generator.h"
#include "Life.h"

typedef struct living_beings {
  Life * being;
  struct living_beings * next;
  struct living_beings * prev;
} living_beings_t;


class Timekeeper {
  private:
    long currentTime;
    float delayBetweenActors;
    living_beings_t * actors = NULL;
    living_beings_t * last = NULL;

  public:
    Timekeeper();
    void update();
    void draw();
    long getTime();
    bool registerObject(Life& o);
};

#endif
