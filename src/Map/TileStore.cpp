/**
 * Stores all information for a generated map and provides utility functions
 */

#include <stdlib.h>

#include "TileStore.h"

int TileStore::mapWidth = 0;
int TileStore::mapHeight = 0;
maptile_t** TileStore::map = NULL;

void TileStore::reset(int width, int height) {
  mapWidth = width;
  mapHeight = height;
  initMap();
}

void TileStore::initMap() {
  int x;
  free(map);

  map = (maptile_t **) malloc(sizeof(maptile_t *) * mapWidth);
  for (x = 0; x < mapWidth; x++) {
    map[x] = (maptile_t *) malloc(sizeof(maptile_t) * mapHeight);
  }
}

bool TileStore::isWalkable(int x, int y) {
  return map[x][y].walkable;
}

char TileStore::getSymbol(int x, int y) {
  return map[x][y].symbol;
}

bool TileStore::defineTile(int x, int y, bool walkable, char symbol) {
  bool retval = false;

  if (x >= 0 && x < mapWidth && y >= 0 && y < mapHeight) {
    retval = true;
    map[x][y].walkable = walkable;
    map[x][y].symbol = symbol;
  }

  return retval;
}

int TileStore::getWidth() {
  return mapWidth;
}

int TileStore::getHeight() {
  return mapHeight;
}
