/**
 * Map generation factory
 */
#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include <stdlib.h>

#include "MapData.h"

using namespace std;

class MapGenerator {
  private:
    MapData* mapData;

  public:
    MapGenerator();
    void generate(int width, int height);
    MapData* getMap();
};

#endif
