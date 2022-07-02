/**
 * Handles display of the viewport of the map plus all objects in it
 */

#include "MapWindow.h"

MapWindow::MapWindow(int startX, int startY, int width, int height) {
  winLeft = startX;
  winTop = startY;
  winWidth = width;
  winHeight = height;

  mapWin = newwin(winHeight, winWidth, winTop, winLeft);
  box(mapWin, 0, 0);
  wborder(mapWin, '|', '|', '-', '-', '+', '+', '+', '+');
  wrefresh(mapWin);
}

void MapWindow::assignMap(MapData* md) {
  mapData = md;
}

void MapWindow::draw() {
  int x, y;
  int width = min(winWidth - 2, mapData->getWidth());
  int height = min(winHeight - 2, mapData->getHeight());

  for (x = 0; x < width; x++) {
    for (y = 0; y < height; y++) {
      mvwaddch(mapWin, y+1, x+1, mapData->getSymbol(x, y));
    }
  }

  wrefresh(mapWin);
}
