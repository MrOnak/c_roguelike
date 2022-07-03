/**
 * Provides the central interactions between Map Objects and the Map
 */
#ifndef MAPINTERFACE_H
#define MAPINTERFACE_H

#include "MapData.h"
#include "MapWindow.h"
#include "MapGenerator.h"

class MapInterface {
  private:
    MapWindow *mapWindow;
    MapGenerator *mapGenerator;

  public:
    void injectMapWindow(MapWindow* mw);
    void injectMapGenerator(MapGenerator &mg);
    void generateNewMap(int width, int height);
};

#endif
