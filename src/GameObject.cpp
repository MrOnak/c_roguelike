#include "GameObject.h"

GameObject::GameObject(int x, int y) {
  pos.x = x;
  pos.y = y;

  symbol = '?';
}

void GameObject::display() {
  mvaddch(pos.y, pos.x, symbol);
}

struct position GameObject::getPos() {
  return pos;
}
