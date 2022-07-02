#include <iostream>
#include <time.h>
#include <curses.h>

#include "Timekeeper.h"
#include "Generator.h"
#include "GameObject.h"
#include "Life.h"
#include "Player.h"
#include "Mouse.h"
#include "Frog.h"

using namespace std;

Timekeeper chronos;
Player player(40, 12);
Mouse mouse(35, 12);
Mouse mouse2(35, 12);
Frog frog(35, 15);

int main(int argc, char *argv[]) {
  // general initialization
  srand(time(NULL));

  // ncurses initialization
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

  // create map
  // initialize and register all GameObjects
  chronos.registerObject(mouse);
  chronos.registerObject(mouse2);
  chronos.registerObject(frog);
  chronos.registerObject(player);

  // start game loop
  attron(COLOR_PAIR(1));

  chronos.draw();

  while (true) {
    // draw (empty) map
    // handle actions of all objects
    chronos.update();
    // draw characters on top of map
    chronos.draw();

    refresh();
  }

  attroff(COLOR_PAIR(1));
  endwin();
  return EXIT_SUCCESS;
}
