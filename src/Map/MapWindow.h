/**
 * Handles display of the viewport of the map plus all objects in it
 */
#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <iostream>
#include <curses.h>
#include <math.h>

using namespace std;

#include "../pos.h"
#include "MapData.h"

class MapWindow {
  private:
    position winPos;
    position winMapOffset;
    position visMapOffset;
    position winSize;
    position usableWinSize;
    position usableWinHalfSize;
    MapData *mapData;
    WINDOW *mapWin;
    void calculateVisMapOffset();
    void calculateUsableSpace();
    bool isVisible(position pos);
    void drawVisibleTerrain();
    void drawThings();
    void drawLife();

  public:
    MapWindow(int startX, int startY, int width, int height);
    void assignMap(MapData* md);
    void draw();
    void drawTile(int x, int y);
    void refresh();
};

#endif
