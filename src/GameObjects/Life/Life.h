#ifndef LIFE_H
#define LIFE_H

#include "../GameObject.h"
#include "../../Map/TileStore.h"

class Life : public GameObject {
  private:
    float energy;

  protected:
    float costFactor;
    float calculateCostOfAction(float rawCost);
    bool consumeEnergy(float e);

  public:
    Life(int x, int y);
    virtual bool act() = 0;
    float getEnergy();
    void addEnergy(float e);
    bool moveBy(int x, int y);
    bool moveTo(int x, int y);
};

#endif
