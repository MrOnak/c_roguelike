/**
 * Map generation factory
 */
#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include <stdlib.h>

#include "MapData.h"
#include "../GameObjects/Life/Player.h"
#include "../GameObjects/Life/Critter/Mouse.h"
#include "../GameObjects/Life/Critter/Frog.h"

class MapGenerator {
  private:
    MapData *mapData;
    void generateTiles(int width, int height);
    void generateThings();
    void generateLife();

  public:
    void generate(int width, int height);
    MapData* getMap();
};

#endif
