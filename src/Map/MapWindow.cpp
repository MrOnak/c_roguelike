/**
 * Handles display of the viewport of the map plus all objects in it
 */

#include "MapWindow.h"

MapWindow::MapWindow(int startX, int startY, int width, int height) {
  winPos.x = startX;
  winPos.y = startY;
  // set offset of the drawable part of the map window to the top-left edge of the border
  winMapOffset.x = 1;
  winMapOffset.y = 1;
  // defines the top-left x/y coordinates of MapData tileset we're actually going to draw
  visMapOffset.x = 0;
  visMapOffset.y = 0;
  winWidth = width;
  winHeight = height;

  mapWin = newwin(winHeight, winWidth, winPos.y, winPos.x);
  box(mapWin, 0, 0);
  wborder(mapWin, '|', '|', '-', '-', '+', '+', '+', '+');
  refresh();
}

void MapWindow::assignMap(MapData* md) {
  mapData = md;
}

void MapWindow::draw() {
  calculateVisMapOffset();
  drawVisibleTerrain();
  drawThings();
  drawLife();

  refresh();
}

void MapWindow::drawTile(int x, int y) {
  mvwaddch(mapWin,
    y + winMapOffset.y + visMapOffset.y,
    x + winMapOffset.x + visMapOffset.x,
    mapData->getSymbol(x, y));
}

void MapWindow::refresh() {
  wrefresh(mapWin);
}

void MapWindow::calculateVisMapOffset() {
  Player* player = mapData->getPlayer();
  position playerPos = player->getPos();
  
  // to be implemented
}

bool MapWindow::isVisible(position pos) {
  return (
    pos.x >= visMapOffset.x && pos.x < visMapOffset.x + winWidth
    && pos.y >= visMapOffset.y && pos.y < visMapOffset.y + winHeight
  );
}

void MapWindow::drawVisibleTerrain() {
  int x, y;
  int width = min(winWidth - 2, mapData->getWidth());
  int height = min(winHeight - 2, mapData->getHeight());

  for (x = 0; x < width; x++) {
    for (y = 0; y < height; y++) {
      drawTile(x, y);
    }
  }
}

void MapWindow::drawThings() {

}

void MapWindow::drawLife() {
  living_beings_t* current = mapData->getLife();
  position pos;
  /* iterate over all creatures and draw them on top of the map
     if they are on the visible part of the map */
  do {
    pos = current->being->getPos();

    if (isVisible(pos)) {
      mvwaddch(mapWin,
        pos.y + winMapOffset.y + visMapOffset.y,
        pos.x + winMapOffset.x + visMapOffset.x,
        current->being->getSymbol());
    }

    current = current->next;
  } while (current->next != NULL);
}
