/**
 * Map generation factory
 */
#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include <stdlib.h>

#include "TileStore.h"
#include "../GameObjects/ObjectStore.h"

#include "../GameObjects/Life/Player.h"
#include "../GameObjects/Life/Critter/Mouse.h"
#include "../GameObjects/Life/Critter/Frog.h"
#include "../GameObjects/Life/Plant/Tree.h"

class MapGenerator {
  private:
    void generateTiles(int width, int height);
    void generateThings();
    void generateVegetation();
    void generateLife();

  public:
    void generate(int width, int height);
};

#endif
