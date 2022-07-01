#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include <signal.h>
#include <curses.h>
#include <math.h>

struct position {
  int x;
  int y;
};

 struct playerchar {
  char symbol;
  struct position pos;
};

struct playerchar player;
long currentTime = 0;

const int WIDTH = 80;
const int HEIGHT = 24;

void timestep() {
  currentTime++;

  // this is a POC, needs major rework
  int c = getch();

  switch(c) {
    case KEY_LEFT:
    case 'a':
      player.pos.x = fmax(0, player.pos.x - 1);
      break;
    case KEY_RIGHT:
    case 'd':
      player.pos.x = fmin(WIDTH, player.pos.x + 1);
      break;
    case KEY_UP:
    case 'w':
      player.pos.y = fmax(0, player.pos.y - 1);
      break;
    case KEY_DOWN:
    case 's':
      player.pos.y = fmin(HEIGHT, player.pos.y + 1);
      break;
    default:
  }
}

int main(int argc, char *argv[]) {
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

  // initialize the world
  player.symbol = '@';
  player.pos.x = 10;
  player.pos.y = 10;

  attron(COLOR_PAIR(1));
  while (true) {
    clear();

    mvaddch(player.pos.y, player.pos.x, player.symbol);
    refresh();
    
    // handle actions of all objects
    timestep();
  }
  attroff(COLOR_PAIR(1));

  endwin();
  return EXIT_SUCCESS;
}
