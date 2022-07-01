#include "Player.h"

Player::Player(int x, int y) : Life(x, y) {
  symbol = '@';
}

void Player::act() {
  int c = getch();

  switch(c) {
    case KEY_LEFT:
    case 'a':
      moveBy(-1, 0);
      break;
    case KEY_RIGHT:
    case 'd':
      moveBy(1, 0);
      break;
    case KEY_UP:
    case 'w':moveBy(0, -1);
      break;
    case KEY_DOWN:
    case 's':moveBy(0, 1);
      break;
  }
}
