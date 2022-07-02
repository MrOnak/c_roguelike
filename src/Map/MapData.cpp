/**
 * Stores all information for a generated map and provides utility functions
 */

#include <stdlib.h>

#include "MapData.h"

MapData::MapData(int width, int height) {
  mapWidth = width;
  mapHeight = height;

  initMap();
}

void MapData::initMap() {
  int x;
  free(map);

  map = (maptile_t **) malloc(sizeof(maptile_t *) * mapWidth);
  for (x = 0; x < mapWidth; x++) {
    map[x] = (maptile_t *) malloc(sizeof(maptile_t) * mapHeight);
  }
}

bool MapData::isWalkable(int x, int y) {
  return map[x][y].walkable;
}

char MapData::getSymbol(int x, int y) {
  return map[x][y].symbol;
}

bool MapData::defineTile(int x, int y, bool walkable, char symbol) {
  bool retval = false;

  if (x >= 0 && x < mapWidth && y >= 0 && y < mapHeight) {
    retval = true;
    map[x][y].walkable = walkable;
    map[x][y].symbol = symbol;
  }

  return retval;
}