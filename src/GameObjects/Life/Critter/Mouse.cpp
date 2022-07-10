#include "Mouse.h"

Mouse::Mouse(int x, int y) : Critter(x, y) {
  symbol = 'm';
  costFactor = 1.0f;
}

bool Mouse::act() {
  // this is a brownian motion behaviour with added rest.
  // needs to be moved into a behaviour file.
  uint8_t dir = rand() % 5 + 1;
  float cost = 0;

  //cost = calculateCostOfAction(1.0f);
  switch(dir) {
    case 1:
      // left
      if (moveBy(-1, 0)) {
        cost = calculateCostOfAction(1.0f);
      }
      break;
    case 2:
      // right
      if (moveBy(1, 0)) {
        cost = calculateCostOfAction(1.0f);
      }
      break;
    case 3:
      // up
      if (moveBy(0, -1)) {
        cost = calculateCostOfAction(1.0f);
      }
      break;
    case 4:
      // down
      if (moveBy(0, 1)) {
        cost = calculateCostOfAction(1.0f);
      }
      break;
    default:
      // resting
      moveBy(0, 0);
  }

  return consumeEnergy(cost);
}
