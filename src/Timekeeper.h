#ifndef TIMEKEEPER_H
#define TIMEKEEPER_H

#include <unistd.h>

#include "Generator.h"
#include "GameObjects/Life/Player.h"
#include "living_beings_t.h"

class Timekeeper {
  private:
    long date;
    long time;
    living_beings_t* current = NULL;

    void distributeEnergy(float e);
    void sortEntity(living_beings_t* entity);
    void progressTime();

  public:
    Timekeeper();
    long getTime();
    long getDate();
    void update();
    void setActors(living_beings_t* actor);
};

#endif
