#ifndef PLAYER_H
#define PLAYER_H

#include "Life.h"
#include <curses.h>

class Player : public Life {
  private:

  public:
    Player(int x, int y);
    void act(); // inherited as pure virtual function from Life
};

#endif
