#ifndef TIMEKEEPER_H
#define TIMEKEEPER_H

#include <curses.h>
#include <unistd.h>

#include "Structs/LivingBeings.h"

class Timekeeper {
  private:
    long date;
    long time;
    living_beings_t* actors = NULL;

    void distributeEnergy(float e);
    void sortEntity(struct living_beings** headRef, living_beings_t** entity);
    void progressTime();

  public:
    Timekeeper();
    long getTime();
    long getDate();
    void update();
    void setActors(living_beings_t* actor);
};

#endif
