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
  // defines the top-left x/y coordinates of TileStore tileset we're actually going to draw
  visMapOffset.x = 0;
  visMapOffset.y = 0;

  mapWin = newwin(winSize.y, winSize.x, winPos.y, winPos.x);
  refreshWindow();

  MapWindow::calculateUsableSpace();
}

void MapWindow::draw() {
  calculateVisMapOffset();
  wclear(mapWin);
  drawVisibleTerrain();
  drawThings();
  drawLife();
  refreshWindow();
}

void MapWindow::drawTile(int x, int y) {
  mvwaddch(mapWin,
    y + winMapOffset.y - visMapOffset.y,
    x + winMapOffset.x - visMapOffset.x,
    TileStore::getSymbol(x, y));
}

void MapWindow::refreshWindow() {
  drawBorder();
  wrefresh(mapWin);
}

void MapWindow::drawBorder() {
  // drawing a custom border since wborder would be overwritten
  // and I can't be asked to create a sub-window for the actual
  // content
  int x, y;
  int c;
  for (x = 1; x < winSize.x-1; x++) {
    mvwaddch(mapWin, 0, x, '-');
    mvwaddch(mapWin, winSize.y-1, x, '-');
  }

  for (y = 0; y < winSize.y; y++) {
    c = '|';
    if (y == 0 || y == winSize.y-1) {
      c = '+';
    }
    mvwaddch(mapWin, y, 0, c);
    mvwaddch(mapWin, y, winSize.x-1, c);
  }

}

void MapWindow::calculateVisMapOffset() {
  position playerPos = ObjectStore::getPlayer()->getPos();

  // calculate offset so that player position is in the center of the usable space
  visMapOffset.x = playerPos.x - usableWinHalfSize.x;
  visMapOffset.y = playerPos.y - usableWinHalfSize.y;
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
}

void MapWindow::drawVisibleTerrain() {
  int x, y;
  position start, end;
  start.x = std::max(0, visMapOffset.x);
  start.y = std::max(0, visMapOffset.y);
  end.x = std::min(TileStore::getWidth(), usableWinSize.x + visMapOffset.x);
  end.y = std::min(TileStore::getHeight(), usableWinSize.y + visMapOffset.y);

  for (x = start.x; x < end.x; x++) {
    for (y = start.y; y < end.y; y++) {
      drawTile(x, y);
    }
  }
}

void MapWindow::drawThings() {

}

void MapWindow::drawLife() {
  living_beings_t* current = *ObjectStore::getLife();
  position pos;
  /* iterate over all creatures and draw them on top of the map
     if they are on the visible part of the map */
  do {
    pos = current->being->getPos();

    //if (isVisible(pos)) {
      mvwaddch(mapWin,
        pos.y + winMapOffset.y - visMapOffset.y,
        pos.x + winMapOffset.x - visMapOffset.x,
        current->being->getSymbol());
    //}

    current = current->next;
  } while (current != NULL);
}
