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

void MapInterface::distributeMap() {
  MapData* mapData = mapGenerator->getMap();
  mapWindow->assignMap(mapData);
}
