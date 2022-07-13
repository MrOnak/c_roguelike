#ifndef TIMEKEEPER_H
#define TIMEKEEPER_H

#include <curses.h>
#include <unistd.h>

#include "../GameObjects/ObjectStore.h"

class Timekeeper {
  private:
    long date;
    long time;
    living_beings_t* pos = NULL;

    void distributeEnergy(float e);
    void sortEntity();

  public:
    Timekeeper();
    void progressTime();
    bool update();
    long getTime();
    long getDate();
};

#endif
