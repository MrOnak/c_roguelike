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
 * if energy budget exceeds cost it is reduced by the amount
 * and method returns true.
 *
 * cost given must be the raw cost. costFactor is applied
 * internally
 */
bool Life::consumeEnergy(float rawCost) {
  float cost = calculateCostOfAction(rawCost);
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
  bool retval = false;
  float rawCost = 1.0f;

  if (TileStore::isWalkable(pos.x + x, pos.y + y)
    && consumeEnergy(rawCost)) {
    pos.x += x;
    pos.y += y;
    retval = true;
  }

  return retval;
}

bool Life::moveTo(int x, int y) {
  bool retval = false;
  float rawCost = 1.0f;

  if (TileStore::isWalkable(x, y)
    && consumeEnergy(rawCost)) {
    pos.x = x;
    pos.y = y;
    retval = true;
  }

  return retval;
}

bool Life::noop() {
  return true;
}
