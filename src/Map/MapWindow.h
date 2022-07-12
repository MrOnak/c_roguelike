/**
 * Handles display of the viewport of the map plus all objects in it
 */
#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <iostream>
#include <curses.h>
#include <math.h>

#include "../pos.h"
#include "TileStore.h"
#include "../GameObjects/ObjectStore.h"

class MapWindow {
  private:
    // position of the ncurses window relative to screen top-left
    position winPos;
    // total size of the ncurses window, including border and padding
    position winSize;
    // ncurses window border padding
    position winMapOffset;
    // defines the top-left x/y coordinates of TileStore tileset we're actually going to draw
    position visMapOffset;
    position usableWinSize;
    position usableWinHalfSize;
    WINDOW *mapWin;
    void calculateVisMapOffset();
    void calculateUsableSpace();
    bool isVisible(position pos);
    void drawVisibleTerrain();
    void drawThings();
    void drawLife();
    void refreshWindow();
    void drawBorder();

  public:
    MapWindow(int startX, int startY, int width, int height);
    void draw();
    void drawTile(int x, int y);
};

#endif
