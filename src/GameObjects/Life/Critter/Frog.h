#ifndef FROG_H
#define FROG_H

#include <cstdint>

#include "Critter.h"

class Frog : public Critter {
  private:

  public:
    Frog(int x, int y);
    bool act(); // inherited as pure virtual function from Life
};

#endif
