#include "Player.h"

Player::Player(int x, int y) : Life(x, y) {
  symbol = '@';
  costFactor = 3.0f;
}

bool Player::act() {
  int c = getch();
  float cost = 0;

  switch(c) {
    case KEY_LEFT:
    case 'a':
      if (moveBy(-1, 0)) {
        cost = calculateCostOfAction(1.0f);
      }
      break;
    case KEY_RIGHT:
    case 'd':
      if (moveBy(1, 0)) {
        cost = calculateCostOfAction(1.0f);
      }
      break;
    case KEY_UP:
    case 'w':
      if (moveBy(0, -1)) {
        cost = calculateCostOfAction(1.0f);
      }
      break;
    case KEY_DOWN:
    case 's':
      if (moveBy(0, 1)) {
        cost = calculateCostOfAction(1.0f);
      }
      break;
  }

  return consumeEnergy(cost);
}
