#ifndef TREE_H
#define TREE_H

#include "Plant.h"

class Tree : public Plant {
  private:

  public:
    Tree(int x, int y);
    bool act(); // inherited as pure virtual function from Life
};

#endif
