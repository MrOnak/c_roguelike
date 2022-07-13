#include <iostream>
#include <time.h>

using namespace std;

#include "../src/Map/TileStore.h"
#include "../src/GameObjects/ObjectStore.h"
#include "../src/Helpers/Timekeeper.h"
#include "../src/GameObjects/Life/Critter/Frog.h"
#include "../src/GameObjects/Life/Critter/Mouse.h"

void initMap() {
  int width = 30;
  int height = 20;
  TileStore::reset(width, height);
  bool walkable;
  char symbol;

  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      walkable = true;
      symbol = ' ';

      if (x == 0 || x == width-1 || y == 0 || y == height-1) {
        walkable = false;
        symbol = '#';
      } else if (rand() % 8 == 0) {
        symbol = ',';
      }

      TileStore::defineTile(x, y, walkable, symbol);
    }
  }
}

void draw() {
  living_beings_t** headRef = ObjectStore::getLife();
  living_beings_t* curr = NULL;

  for (curr = *headRef; curr != NULL; curr = curr->next) {
    printf("%d/%d %c#%ld(e:%.0f c:%0.f) - ",
      curr->being->getPos().x, curr->being->getPos().y,
      curr->being->getSymbol(), curr->being->getId(),
      curr->being->getEnergy(), curr->being->getCostFactor());
  }
  printf("\n");
}

void initCreatures() {
  Mouse* mouse1 = new Mouse(10, 10);
  Mouse* mouse2 = new Mouse(11, 11);
  Frog* frog1 = new Frog(5, 5);

  ObjectStore::registerLife(*mouse1);
  ObjectStore::registerLife(*mouse2);
  ObjectStore::registerLife(*frog1);
}

int main(int argc, char* argv[]) {
  printf("Testing main game-loop with actual game objects\n\n");

  Timekeeper timekeeper;

  initMap();
  initCreatures();

  draw();

  while (true) {
    printf("--- new game loop\n");
    timekeeper.progressTime();
    draw();

    printf("----- acting on entities\n");
    while (timekeeper.update()) {
      draw();
    }
    int c = getchar();
  }

  return EXIT_SUCCESS;
}
