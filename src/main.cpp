#include <iostream>
#include <time.h>
#include <curses.h>

#include "Timekeeper.h"
#include "Map/MapWindow.h"
#include "Map/MapGenerator.h"

#include "Map/TileStore.h"
#include "GameObjects/ObjectStore.h"
/*

using namespace std;
*/

MapGenerator mapGenerator;
MapWindow *mapWindow;
Timekeeper timekeeper;

void initNCurses() {
  initscr();
  refresh();
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
  // generate and distribute map data - includes objects and creatures
  mapGenerator.generate(50, 17);
}

int main(int argc, char *argv[]) {
  // general initialization
  srand(time(NULL));

  initNCurses();
  initGameEnvironment();

  // start game loop
  attron(COLOR_PAIR(1));

  mapWindow->draw();
  /*
  */

  while (true) {
    // update all entities
    timekeeper.update();
    //refresh(); // for debugging

    // draw map
    mapWindow->draw();
    usleep(500000);
  }
  int c = getch(); // this is to keep the debug screen visible before program exits

  attroff(COLOR_PAIR(1));
  endwin();
  return EXIT_SUCCESS;
}
