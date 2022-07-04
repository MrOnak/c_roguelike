#include <iostream>
#include <time.h>
#include <curses.h>

#include "Timekeeper.h"
#include "Generator.h"
#include "Map/MapInterface.h"
#include "Map/MapWindow.h"
#include "Map/MapGenerator.h"
#include "Map/MapData.h"

using namespace std;

MapInterface mapInterface;
MapGenerator mapGenerator;
MapWindow *mapWindow;
Timekeeper timekeeper;

void initNCurses() {
  initscr();
  cbreak();
  noecho();
  curs_set(0);

  if (has_colors() == false) {
    endwin();
    printf("Your terminal does not support color\n");
    exit(1);
  }
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_GREEN);
  init_pair(3, COLOR_WHITE, COLOR_WHITE);
}

void initGameEnvironment() {
  mapWindow = new MapWindow(0, 0, 62, 22);
  // inject everything into map interface
  mapInterface.injectMapWindow(mapWindow);
  mapInterface.injectMapGenerator(mapGenerator);
  // generate and distribute map data - includes objects and creatures
  mapInterface.generateNewMap(50, 17);
}

int main(int argc, char *argv[]) {
  // general initialization
  srand(time(NULL));

  initNCurses();
  initGameEnvironment();

  // start game loop
  attron(COLOR_PAIR(1));

  while (true) {
    // draw terrain
    mapWindow->draw();
  }

  attroff(COLOR_PAIR(1));
  endwin();
  return EXIT_SUCCESS;
}
