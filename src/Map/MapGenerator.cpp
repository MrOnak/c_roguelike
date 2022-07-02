/**
 * Map generation factory
 */

#include "MapGenerator.h"

MapGenerator::MapGenerator() {}

void MapGenerator::generate(int width, int height) {
  mapData = new MapData(width, height);
  bool walkable;
  char symbol;

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      walkable = true;
      symbol = ' ';

      if (x == 0 || x == width-1 || y == 0 || y == height-1) {
        walkable = false;
        symbol = '#';
      } else if (rand() % 8 == 0) {
        symbol = ',';
      }

      mapData->defineTile(x, y, walkable, symbol);
    }
  }
}

MapData* MapGenerator::getMap() {
  return mapData;
}
