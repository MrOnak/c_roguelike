#ifndef CRITTER_H
#define CRITTER_H

#include <curses.h>

#include "../Life.h"

class Critter : public Life {
  private:

  public:
    Critter(int x, int y);
    void act(); // inherited as pure virtual function from Life
};

#endif