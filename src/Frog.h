#ifndef FROG_H
#define FROG_H

#include "Life.h"
#include <curses.h>
#include <stdlib.h>

class Frog : public Life {
  private:

  public:
    Frog(int x, int y);
    void act(); // inherited as pure virtual function from Life
};

#endif
