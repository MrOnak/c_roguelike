#include "GameObject.h"

GameObject::GameObject(int x, int y) {
  id = Generator::getId();
  pos.x = x;
  pos.y = y;

  symbol = '?';
}

void GameObject::display() {
  mvaddch(pos.y, pos.x, symbol);
}

position GameObject::getPos() {
  return pos;
}

char GameObject::getSymbol() {
  return symbol;
}
