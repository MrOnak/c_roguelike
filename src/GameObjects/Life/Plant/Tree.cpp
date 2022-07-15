#include "Tree.h"

Tree::Tree(int x, int y) : Plant(x, y) {
  symbol = 'T';
  costFactor = 1.0f;
}

bool Tree::act() {
  return false;
}
