#ifndef PLAYER_H
#define PLAYER_H

#include <curses.h>
#include "Life.h"

class Player : public Life {
  private:

  public:
    Player(int x, int y);
    bool act(); // inherited as pure virtual function from Life
};

#endif
