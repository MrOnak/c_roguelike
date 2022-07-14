#ifndef TIMEKEEPER_H
#define TIMEKEEPER_H

#include <curses.h>
#include <unistd.h>

#include "../GameObjects/ObjectStore.h"
#include "Logger.h"

class Timekeeper {
  private:
    static long date;
    static long time;
    living_beings_t* pos = NULL;

    void distributeEnergy(float e);
    void sortEntity();

  public:
    Timekeeper();
    void progressTime();
    bool update();
    static long getTime();
    static long getDate();
};

#endif
