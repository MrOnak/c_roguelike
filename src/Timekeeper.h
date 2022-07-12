#ifndef TIMEKEEPER_H
#define TIMEKEEPER_H

#include <curses.h>
#include <unistd.h>

#include "GameObjects/ObjectStore.h"

class Timekeeper {
  private:
    long date;
    long time;
    living_beings_t* actors = NULL;

    void distributeEnergy(float e);
    void sortEntity(struct living_beings** headRef, living_beings_t** entity);

  public:
    Timekeeper();
    void progressTime();
    void update();
    long getTime();
    long getDate();
    void setActors(living_beings_t* actor);
};

#endif
