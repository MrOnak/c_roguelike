/**
 * Stores all information for a generated map and provides utility functions
 */
#ifndef MAPDATA_H
#define MAPDATA_H

#include "../living_beings_t.h"
#include "../GameObjects/Life/Player.h"

typedef struct maptile {
 bool walkable;
 char symbol;
} maptile_t;

class MapData {
  private:
    int mapWidth;
    int mapHeight;
    maptile_t **map;
    living_beings_t * actors = NULL;
    living_beings_t * last = NULL;
    Player* player;

    void initMap();

  public:
    MapData(int width, int height);
    bool isWalkable(int x, int y);
    char getSymbol(int x, int y);
    bool defineTile(int x, int y, bool walkable, char symbol);
    int getWidth();
    int getHeight();
    bool registerPlayer(Player* p);
    bool registerObject(Life& o);
    Player* getPlayer();
    living_beings_t* getLife();
};

#endif
