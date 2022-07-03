#ifndef TIMEKEEPER_H
#define TIMEKEEPER_H

#include <unistd.h>

#include "Generator.h"
#include "GameObjects/Life.h"

typedef struct living_beings {
  Life * being;
  struct living_beings * next;
  struct living_beings * prev;
} living_beings_t;


class Timekeeper {
  private:
    long currentTime;
    int delayBetweenActors; // in milliseconds
    living_beings_t * actors = NULL;
    living_beings_t * last = NULL;
    living_beings_t * current = NULL;
    void draw();

  public:
    Timekeeper();
    void update();
    long getTime();
    bool registerObject(Life& o);
    Life* getCurrentObject();
};

#endif
