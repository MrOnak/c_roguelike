#include "GameObject.h"

GameObject::GameObject(int x, int y) {
  id = Generator::getId();
  pos.x = x;
  pos.y = y;

  symbol = '?';
}

position GameObject::getPos() {
  return pos;
}

char GameObject::getSymbol() {
  return symbol;
}

long GameObject::getId() {
  return id;
}
