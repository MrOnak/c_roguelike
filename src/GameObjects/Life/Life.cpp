#include "Life.h"

Life::Life(int x, int y) : GameObject(x, y) {
  energy = 0.0f;
  costFactor = 1.0f;
}

/**
 * override this to add local effects
 */
float Life::calculateCostOfAction(float rawCost) {
  return rawCost * costFactor;
}

/**
 * returns false if energy budget is lower than given cost.
 * if energy budget exceeds cost it is reduced by the amount and method returns true
 */
bool Life::consumeEnergy(float cost) {
  bool retval = (energy >= cost);

  if (retval) {
    energy -= cost;
  }

  return retval;
}

float Life::getEnergy() {
  return energy;
}

float Life::getCostFactor() {
  return costFactor;
}

void Life::addEnergy(float e) {
  energy += e;
}

bool Life::moveBy(int x, int y) {
  bool retval = TileStore::isWalkable(pos.x + x, pos.y + y);

  if (retval) {
    pos.x += x;
    pos.y += y;
  }

  return retval;
}

bool Life::moveTo(int x, int y) {
  bool retval = TileStore::isWalkable(x, y);

  if (retval) {
    pos.x = x;
    pos.y = y;
  }

  return retval;
}
