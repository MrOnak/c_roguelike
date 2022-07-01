#include <iostream>
#include <curses.h>

#include "Timekeeper.h"
#include "GameObject.h"
#include "Life.h"
#include "Player.h"

using namespace std;

Timekeeper tc;
Player player(40, 12);

const int WIDTH = 80;
const int HEIGHT = 24;


int main(int argc, char *argv[]) {
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
  tc.registerObject(player);

  // start game loop
  attron(COLOR_PAIR(1));

  while (true) {
    // draw (empty) map
    // handle actions of all objects
    tc.step();
    refresh();

  }

  attroff(COLOR_PAIR(1));
  endwin();
  return EXIT_SUCCESS;
}
