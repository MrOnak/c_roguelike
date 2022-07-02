#include <iostream>
#include <time.h>

#include "../src/Map/MapGenerator.h"

using namespace std;

MapGenerator gen;

int main(int argc, char *argv[]) {
  cout << "Hello\n";
  gen.generate(20, 10);

  return EXIT_SUCCESS;
}
