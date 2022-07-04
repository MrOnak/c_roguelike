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
#include "GameObjects/Life/Life.h"
#include "GameObjects/Life/Player.h"
#include "GameObjects/Life/Critter/Mouse.h"
#include "GameObjects/Life/Critter/Frog.h"

using namespace std;

MapInterface mapInterface;
MapGenerator mapGenerator;
MapWindow *mapWindow;
Timekeeper timekeeper;

Player player(10, 5);
Mouse mouse(15, 5);
Mouse mouse2(12, 3);
Frog frog(10, 7);

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
  // generate and distribute map data
  mapInterface.generateNewMap(50, 17);

  // initialize and register all GameObjects
  timekeeper.registerObject(mouse);
  timekeeper.registerObject(mouse2);
  timekeeper.registerObject(frog);
  timekeeper.registerPlayer(player);
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

    Life* current = timekeeper.getCurrentObject();
    current->display();
    mvprintw(0, 0, "%d/%d %c", current->getPos().x, current->getPos().y, current->getSymbol());
    // handle actions of all actors, also draws them
    //timekeeper.update();

    //mapWindow->refresh();
    refresh();
  }

  attroff(COLOR_PAIR(1));
  endwin();
  return EXIT_SUCCESS;
}
