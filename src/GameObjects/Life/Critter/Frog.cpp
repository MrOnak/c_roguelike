#include "Frog.h"

Frog::Frog(int x, int y) : Critter(x, y) {
  symbol = 'f';
  costFactor = 2.0f;
}

bool Frog::act() {
  // this is a brownian motion behaviour with added rest.
  // needs to be moved into a behaviour file.
  uint8_t dir = rand() % 5 + 1;
  bool retval = false;

  switch(dir) {
    case 1:
      // left
      retval = moveBy(-1, 0);
      break;
    case 2:
      // right
      retval = moveBy(1, 0);
      break;
    case 3:
      // up
      retval = moveBy(0, -1);
      break;
    case 4:
      // down
      retval = moveBy(0, 1);
      break;
    default:
      // resting
      noop();
  }

  return retval;
}
