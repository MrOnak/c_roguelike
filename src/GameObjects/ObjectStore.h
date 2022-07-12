#ifndef OBJECTSTORE_H
#define OBJECTSTORE_H

#include "../Structs/LivingBeings.h"
#include "../GameObjects/Life/Life.h"
#include "../GameObjects/Life/Player.h"

class ObjectStore {
  private:
    static living_beings_t* actors;
    static Player* player;
    ObjectStore();

  public:
    static bool registerPlayer(Player* p);
    static bool registerLife(Life& o);
    static Player* getPlayer();
    static living_beings_t** getLife();
};

#endif
