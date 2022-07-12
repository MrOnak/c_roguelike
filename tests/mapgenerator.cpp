#include <iostream>
#include <time.h>

#include "../src/Map/MapGenerator.h"
#include "../src/Map/TileStore.h"

using namespace std;

MapGenerator gen;

int main(int argc, char *argv[]) {
  cout << "Hello\n";
  gen.generate(20, 10);

  for (int y = 0; y < 10; y++) {
    for (int x = 0; x < 20; x++) {
      printf("%c", TileStore::getSymbol(x, y));
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
