#include <iostream>
#include <time.h>
#include <unistd.h>
#include <curses.h>

#include "../src/Map/MapData.h"

MapData* mapData;
Player* player;

void init() {
  mapData = new MapData(50, 17);
  Player* pl = new Player(10, 5);
  mapData->registerPlayer(pl);
}

int main(int argc, char* argv[]) {
  init();

  while (true) {
    printf("main.c: calling mapGenerator.getMap()->getPlayer()\n");
    player = mapData->getPlayer();
    printf("main.c: %d/%d #%ld %c\n",
      player->getPos().x, player->getPos().y,
      player->getId(),
      player->getSymbol());
    usleep(50000);
  }

  return EXIT_SUCCESS;
}
