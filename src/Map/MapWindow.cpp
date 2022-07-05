/**
 * Handles display of the viewport of the map plus all objects in it
 */

#include "MapWindow.h"

MapWindow::MapWindow(int startX, int startY, int width, int height) {
  // position of the ncurses window relative to screen top-left
  winPos.x = startX;
  winPos.y = startY;
  // total size of the ncurses window, including border and padding
  winSize.x = width;
  winSize.y = height;
  // ncurses window border padding
  winMapOffset.x = 1;
  winMapOffset.y = 1;
  // defines the top-left x/y coordinates of MapData tileset we're actually going to draw
  visMapOffset.x = 0;
  visMapOffset.y = 0;

  mapWin = newwin(winSize.y, winSize.x, winPos.y, winPos.x);
  box(mapWin, 0, 0);
  wborder(mapWin, '|', '|', '-', '-', '+', '+', '+', '+');
  refresh();

  MapWindow::calculateUsableSpace();
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
    y + winMapOffset.y - visMapOffset.y,
    x + winMapOffset.x - visMapOffset.x,
    mapData->getSymbol(x, y));
}

void MapWindow::refresh() {
  wrefresh(mapWin);
}

void MapWindow::calculateVisMapOffset() {
  position playerPos = mapData->getPlayer()->getPos();

  // calculate offset so that player position is in the center of the usable space
  visMapOffset.x = playerPos.x - usableWinHalfSize.x;
  visMapOffset.y = playerPos.y - usableWinHalfSize.y;
  /*
  mvwprintw(mapWin, 0, 27,
    " player: %d/%d; visOffset: %d/%d",
    playerPos.x, playerPos.y, visMapOffset.x, visMapOffset.y);
    */
}

bool MapWindow::isVisible(position pos) {
  return (
    pos.x >= visMapOffset.x &&
    pos.x < visMapOffset.x + usableWinSize.x &&
    pos.y >= visMapOffset.y &&
    pos.y < visMapOffset.y + usableWinSize.y
  );
}

void MapWindow::calculateUsableSpace() {
  usableWinSize.x = winSize.x - 2 * winMapOffset.x;
  usableWinSize.y = winSize.y - 2 * winMapOffset.y;
  usableWinHalfSize.x = usableWinSize.x / 2;
  usableWinHalfSize.y = usableWinSize.y / 2;
  /*
  mvwprintw(mapWin, 0, 0,
    "use: %d/%d; halfUse: %d/%d;",
    usableWinSize.x, usableWinSize.y,
    usableWinHalfSize.x, usableWinHalfSize.y
  );
  */
}

void MapWindow::drawVisibleTerrain() {
  int x, y;
  position start, end;
  start.x = max(0, visMapOffset.x);
  start.y = max(0, visMapOffset.y);
  end.x = min(mapData->getWidth(), usableWinSize.x + visMapOffset.x);
  end.y = min(mapData->getHeight(), usableWinSize.y + visMapOffset.y);

  //mvwprintw(mapWin, 21, 0, "%d/%d -> %d/%d", start.x, start.y, end.x, end.y);
  for (x = start.x; x < end.x; x++) {
    for (y = start.y; y < end.y; y++) {
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
        pos.y + winMapOffset.y - visMapOffset.y,
        pos.x + winMapOffset.x - visMapOffset.x,
        current->being->getSymbol());
    }

    current = current->next;
  } while (current->next != NULL);
}
