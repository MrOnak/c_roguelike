#include "ObjectStore.h"

living_beings_t* ObjectStore::actors = NULL;
Player* ObjectStore::player = NULL;

bool ObjectStore::registerPlayer(Player* p) {
  player = p;
  registerLife(*p);

  return true;
}

bool ObjectStore::registerLife(Life& o) {
  // create next slot in the linked list and link it
  LivingBeings::push(&actors, o);

  return true;
}

Player* ObjectStore::getPlayer() {
  return player;
}

living_beings_t** ObjectStore::getLife() {
  return &actors;
}
