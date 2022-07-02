#ifndef MOUSE_H
#define MOUSE_H

#include "Life.h"
#include <curses.h>
#include <stdlib.h>

class Mouse : public Life {
  private:

  public:
    Mouse(int x, int y);
    void act(); // inherited as pure virtual function from Life
};

#endif
