/**
 * Map generation factory
 */

#include "MapGenerator.h"

void MapGenerator::generate(int width, int height) {
  generateTiles(width, height);
  generateThings();
  generateLife();
}

MapData* MapGenerator::getMap() {
  return mapData;
}

void MapGenerator::generateTiles(int width, int height) {
  mapData = new MapData(width, height);
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

      mapData->defineTile(x, y, walkable, symbol);
    }
  }
}

void MapGenerator::generateThings() {

}

void MapGenerator::generateLife() {
  Player* player = new Player(1, 5);
  mapData->registerPlayer(player);

  Mouse* mouse = new Mouse(15, 5);
  Mouse* mouse2 = new Mouse(12, 3);
  Frog* frog = new Frog(10, 7);

  mapData->registerObject(*mouse);
  mapData->registerObject(*mouse2);
  mapData->registerObject(*frog);
}
