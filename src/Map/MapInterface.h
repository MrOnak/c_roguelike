/**
 * Provides the central interactions between Map Objects and the Map
 */
#ifndef MAPINTERFACE_H
#define MAPINTERFACE_H

#include "MapWindow.h"
#include "MapGenerator.h"
#include "../Timekeeper.h"

class MapInterface {
  private:
    static MapWindow* mapWindow;
    static MapGenerator* mapGenerator;
    static Timekeeper* timekeeper;
    MapInterface();

  public:
    static void injectMapWindow(MapWindow* mw);
    static void injectMapGenerator(MapGenerator &mg);
    static void injectTimekeeper(Timekeeper &tk);
    static void generateNewMap(int width, int height);
    static bool isTileWalkable(int x, int y);
};

#endif
