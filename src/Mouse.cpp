#include "Mouse.h"

Mouse::Mouse(int x, int y) : Life(x, y) {
  symbol = 'm';
}

void Mouse::act() {
  // this is a brownian motion behaviour with added rest.
  // needs to be moved into a behaviour file.
  uint8_t dir = rand() % 5 + 1;

  switch(dir) {
    case 1:
      // left
      moveBy(-1, 0);
      break;
    case 2:
      // right
      moveBy(1, 0);
      break;
    case 3:
      // up
      moveBy(0, -1);
      break;
    case 4:
      // down
      moveBy(0, 1);
      break;
    default:
      // resting
      moveBy(0, 0);
  }
}
