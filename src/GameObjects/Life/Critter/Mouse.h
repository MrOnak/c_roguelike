#ifndef MOUSE_H
#define MOUSE_H

#include <cstdint>

#include "Critter.h"

class Mouse : public Critter {
  private:

  public:
    Mouse(int x, int y);
    bool act(); // inherited as pure virtual function from Life
};

#endif
