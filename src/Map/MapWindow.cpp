/**
 * Handles display of the viewport of the map plus all objects in it
 */

#include "MapWindow.h"

MapWindow::MapWindow(int startX, int startY, int width, int height) {
  winPos.x = startX;
  winPos.y = startY;
  mapOffset.x = 1;
  mapOffset.y = 1;
  winWidth = width;
  winHeight = height;

  mapWin = newwin(winHeight, winWidth, winPos.y, winPos.x);
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
      drawTile(x, y);
    }
  }

  refresh();
}

void MapWindow::drawTile(int x, int y) {
  mvwaddch(mapWin, y + mapOffset.y, x + mapOffset.x, mapData->getSymbol(x, y));
}

void MapWindow::refresh() {
  wrefresh(mapWin);
}
