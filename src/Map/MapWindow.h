/**
 * Handles display of the viewport of the map plus all objects in it
 */
#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <iostream>
#include <curses.h>

using namespace std;

#include "../pos.h"
#include "MapData.h"

class MapWindow {
  private:
    position winPos;
    position mapOffset;
    int winWidth;
    int winHeight;
    MapData *mapData;
    WINDOW *mapWin;

  public:
    MapWindow(int startX, int startY, int width, int height);
    void assignMap(MapData* md);
    void draw();
    void drawTile(int x, int y);
    void refresh();
};

#endif
