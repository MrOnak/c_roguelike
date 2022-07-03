#include <iostream>
#include <time.h>
#include <curses.h>

#include "Timekeeper.h"
#include "Generator.h"
#include "Map/MapInterface.h"
#include "Map/MapWindow.h"
#include "Map/MapGenerator.h"
#include "Map/MapData.h"
#include "GameObjects/GameObject.h"
#include "GameObjects/Life.h"
#include "GameObjects/Player.h"
#include "GameObjects/Mouse.h"
#include "GameObjects/Frog.h"

using namespace std;

MapInterface mapInterface;
MapGenerator mapGenerator;
MapWindow *mapWindow;
Timekeeper chronos;

Player player(40, 12);
Mouse mouse(35, 12);
Mouse mouse2(35, 12);
Frog frog(35, 15);

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
  mapWindow = new MapWindow(0, 0, 80, 22);
  // inject everything into map interface
  mapInterface.injectMapWindow(mapWindow);
  mapInterface.injectMapGenerator(mapGenerator);
  // generate and distribute map data
  mapGenerator.generate(100, 100);
  mapInterface.distributeMap();

  // initialize and register all GameObjects
  chronos.registerObject(mouse);
  chronos.registerObject(mouse2);
  chronos.registerObject(frog);
  chronos.registerObject(player);
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

    // handle actions of all actors, also draws them
    //chronos.update();

    //refresh();
  }

  attroff(COLOR_PAIR(1));
  endwin();
  return EXIT_SUCCESS;
}
