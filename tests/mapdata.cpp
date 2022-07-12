#include <iostream>
#include <time.h>
#include <unistd.h>
#include <curses.h>

#include "../src/Map/TileStore.h"
#include "../src/GameObjects/ObjectStore.h"

Player* player;

void init() {
  TileStore::reset(50, 17);
  Player* pl = new Player(10, 5);
  ObjectStore::registerPlayer(pl);
}

int main(int argc, char* argv[]) {
  init();

  while (true) {
    printf("main.c: calling mapGenerator.getMap()->getPlayer()\n");
    player = ObjectStore::getPlayer();
    printf("main.c: %d/%d #%ld %c\n",
      player->getPos().x, player->getPos().y,
      player->getId(),
      player->getSymbol());
    usleep(50000);
  }

  return EXIT_SUCCESS;
}
