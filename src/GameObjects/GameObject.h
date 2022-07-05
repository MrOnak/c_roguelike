#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <curses.h>

#include "../pos.h"
#include "../Generator.h"

class GameObject {
  private:

  protected:
    position pos;
    char symbol;

  public:
    long id;

    GameObject(int x, int y);
    void display();
    position getPos();
    char getSymbol();
    long getId();
};

#endif
