#ifndef MOUSE_H
#define MOUSE_H

#include <curses.h>
#include <stdlib.h>

#include "Life.h"

class Mouse : public Life {
  private:

  public:
    Mouse(int x, int y);
    void act(); // inherited as pure virtual function from Life
};

#endif
