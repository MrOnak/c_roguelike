#ifndef CRITTER_H
#define CRITTER_H

#include "Life.h"
#include <curses.h>

class Critter : public Life {
  private:

  public:
    Critter(int x, int y);
    void act(); // inherited as pure virtual function from Life
};

#endif
