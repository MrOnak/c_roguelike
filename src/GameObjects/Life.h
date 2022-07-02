#ifndef LIFE_H
#define LIFE_H

#include "GameObject.h"

class Life : public GameObject {
  private:

  public:
    Life(int x, int y);
    virtual void act() = 0;
    bool moveBy(int x, int y);
    bool moveTo(int x, int y);
};

#endif
