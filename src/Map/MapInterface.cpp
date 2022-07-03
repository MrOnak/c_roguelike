/**
 * Provides the central interactions between Map Objects and the Map
 */
#include "MapInterface.h"

MapInterface::MapInterface() {

}

void MapInterface::injectMapWindow(MapWindow* mw) {
  mapWindow = mw;
}

void MapInterface::injectMapGenerator(MapGenerator &mg) {
  mapGenerator = &mg;
}

void MapInterface::generateNewMap(int width, int height) {
  mapGenerator->generate(width, height);
  mapWindow->assignMap(mapGenerator->getMap());
}
