#include <iostream>
#include <time.h>
#include <filesystem>
#include <curses.h>

#include "Helpers/Timekeeper.h"
#include "Helpers/Logger.h"
#include "Map/MapWindow.h"
#include "Map/MapGenerator.h"

#include "Map/TileStore.h"
#include "GameObjects/ObjectStore.h"

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
  Logger::log("ncurses initialized", Logger::LVL_DEBUG);
}

void initGameEnvironment() {
  mapWindow = new MapWindow(0, 0, 62, 22);
  // generate and distribute map data - includes objects and creatures
  Logger::log("generating map...", Logger::LVL_DEBUG);
  mapGenerator.generate(50, 17);
  Logger::log("game environment is set up", Logger::LVL_DEBUG);
}

int main(int argc, char *argv[]) {
  // general initialization
  srand(time(NULL));
  // logging
  std::string path = std::filesystem::canonical(argv[0]).parent_path();
  std::string logfile = path + "/log/roguelike.log";
  Logger::setFile(logfile, Logger::LVL_DEBUG);
  Logger::log("-----------------", Logger::LVL_INFO);
  Logger::log("initializing game", Logger::LVL_INFO);

  initNCurses();
  initGameEnvironment();

  // start game loop
  attron(COLOR_PAIR(1));

  mapWindow->draw();

  while (true) {
    // this is a time step: distribute new energy to all entities
    timekeeper.progressTime();

    // update all entities one by one and refresh the screen
    while (timekeeper.update()) {
      mapWindow->draw();
      usleep(100000);
    }
  }

  attroff(COLOR_PAIR(1));
  endwin();
  return EXIT_SUCCESS;
}
