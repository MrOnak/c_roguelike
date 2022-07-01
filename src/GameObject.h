#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <curses.h>

struct position {
  int x;
  int y;
};

class GameObject {
  private:

  protected:
    struct position pos;

  public:
    char symbol;

    GameObject(int x, int y);
    void display();
    struct position getPos();
};

#endif
