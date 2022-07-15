/**
 * Map generation factory
 */

#include "MapGenerator.h"

void MapGenerator::generate(int width, int height) {
  generateTiles(width, height);
  generateThings();
  generateVegetation();
  generateLife();
}

void MapGenerator::generateTiles(int width, int height) {
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

void MapGenerator::generateThings() {

}

void MapGenerator::generateVegetation() {
  for (int i = 0; i < 100; i++) {
    Tree* tree = new Tree(rand() % (TileStore::getWidth()-2) + 1, rand() % (TileStore::getHeight()-2) + 1);
    ObjectStore::registerLife(*tree);
  }
}

void MapGenerator::generateLife() {
  Player* player = new Player(1, 5);
  ObjectStore::registerPlayer(player);

  Mouse* mouse = new Mouse(15, 5);
  Mouse* mouse2 = new Mouse(12, 3);
  Frog* frog = new Frog(10, 7);

  ObjectStore::registerLife(*mouse);
  ObjectStore::registerLife(*mouse2);
  ObjectStore::registerLife(*frog);
}
