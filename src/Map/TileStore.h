/**
 * Stores all information for a generated map and provides utility functions
 */
#ifndef TILESTORE_H
#define TILESTORE_H

typedef struct maptile {
  bool walkable;
  char symbol;
} maptile_t;

class TileStore {
  private:
    static int mapWidth;
    static int mapHeight;
    static maptile_t **map;

    static void initMap();
    TileStore();

  public:
    static void reset(int width, int height);
    static bool isWalkable(int x, int y);
    static char getSymbol(int x, int y);
    static bool defineTile(int x, int y, bool walkable, char symbol);
    static int getWidth();
    static int getHeight();
};

#endif
