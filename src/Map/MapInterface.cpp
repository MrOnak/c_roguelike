/**
 * Provides the central interactions between Map Objects and the Map
 */
#include "MapInterface.h"

MapWindow* MapInterface::mapWindow = NULL;
MapGenerator* MapInterface::mapGenerator = NULL;
Timekeeper* MapInterface::timekeeper = NULL;

void MapInterface::injectMapWindow(MapWindow* mw) {
  mapWindow = mw;
}

void MapInterface::injectMapGenerator(MapGenerator &mg) {
  mapGenerator = &mg;
}

void MapInterface::injectTimekeeper(Timekeeper &tk) {
  timekeeper = &tk;
}

void MapInterface::generateNewMap(int width, int height) {
  mapGenerator->generate(width, height);
  mapWindow->assignMap(mapGenerator->getMap());
  timekeeper->setActors(mapGenerator->getMap()->getLife());
}

bool MapInterface::isTileWalkable(int x, int y) {
  return mapGenerator->getMap()->isWalkable(x, y);
}
