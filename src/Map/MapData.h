/**
 * Stores all information for a generated map and provides utility functions
 */
#ifndef MAPDATA_H
#define MAPDATA_H

typedef struct maptile {
 bool walkable;
 char symbol;
} maptile_t;

class MapData {
  private:
    int mapWidth;
    int mapHeight;
    maptile_t **map;

    void initMap();

  public:
    MapData(int width, int height);
    bool isWalkable(int x, int y);
    char getSymbol(int x, int y);
    bool defineTile(int x, int y, bool walkable, char symbol);
    int getWidth();
    int getHeight();
};

#endif
