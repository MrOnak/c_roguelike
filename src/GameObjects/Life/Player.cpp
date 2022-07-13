#include "Player.h"

Player::Player(int x, int y) : Life(x, y) {
  symbol = '@';
  costFactor = 3.0f;
}

bool Player::act() {
  bool retval = false;
  // don't even try to act if energy is lower than costFactor
  if (getEnergy() >= costFactor) {
    int c = getch();

    switch(c) {
      case KEY_LEFT:
      case 'a':
        retval = moveBy(-1, 0);
        break;
      case KEY_RIGHT:
      case 'd':
        retval = moveBy(1, 0);
        break;
      case KEY_UP:
      case 'w':
        retval = moveBy(0, -1);
        break;
      case KEY_DOWN:
      case 's':
        retval = moveBy(0, 1);
        break;
    }
  }

  return retval;
}
