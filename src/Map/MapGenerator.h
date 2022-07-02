/**
 * Map generation factory
 */
#include <stdlib.h>

#include "MapData.h"

using namespace std;

class MapGenerator {
  private:
    MapData* mapData;

  public:
    MapGenerator();
    void generate(int width, int height);
};
