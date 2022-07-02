#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <curses.h>

#include "../Generator.h"

struct position {
  int x;
  int y;
};

class GameObject {
  private:

  protected:
    position pos;

  public:
    long id;
    char symbol;

    GameObject(int x, int y);
    void display();
    position getPos();
};

#endif
