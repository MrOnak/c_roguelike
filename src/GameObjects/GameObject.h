#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

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
    position getPos();
    char getSymbol();
    long getId();
};

#endif
