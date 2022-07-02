#include "Life.h"

Life::Life(int x, int y) : GameObject(x, y) {
}

bool Life::moveBy(int x, int y) {
  pos.x += x;
  pos.y += y;

  return true;
}

bool Life::moveTo(int x, int y) {
  pos.x = x;
  pos.y = y;

  return true;
}
