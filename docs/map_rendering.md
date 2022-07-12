# map rendering

## overview of map-handling classes
### TileStore
The static instance of TileStore contains information about the map tiles.

Inanimate objects and living beings are stored in ObjectStore.

TileStore has no concept of how and where to display this information.

TileStore has no concept of time or progression thereof. TileStore is manipulated externally as time progresses, living beings interact with the environment and each other.

### MapGenerator
The MapGenerator is a map factory that can produce all maps, terrains and biomes and construct a TileStore instance with all the data.

MapGenerator also populates the generated terrain with inanimate objects and living beings and stores those in ObjectStore.

During gameplay on a generated map the MapGenerator isn't relevant, it merely generates the data structures within TileStore.

### MapWindow
The MapWindow instance is the GUI that is capable of displaying the map (or a portion of it) inside an ncurses window.

MapWindow has no concept of time or progression thereof. It is simply triggered to draw characters inside its ncurses window.

## step-based map drawing
The following describes the sequence of steps implemented to display the visible portion of the map on the game screen.

1. get `Player` position
2. set `MapWindow.offset` so that the `Player` in the center of the visible map window
3. draw all map tiles of the visible portion of the screen
4. iterate over `GameThing`, that is inanimate objects, and display them if they are on the visible portion of the screen.
5. iterate over `Life`, that is all living beings, and display them if they are on the visible portion of the screen.

### optimizations and further extensions
* the whole map only needs to be (re-)drawn if the map offset has changed, that is, if the `Player` has moved.
* all `GameObjects` could have a `GameObject.dirty` flag to indicate whether they need to be re-drawn or not. That way a tree that isn't interacted with doesn't have to be re-drawn every game step. Same with `Life` instances that don't move or interact
* If the whole map _isn't_ re-drawn every step care must be taken to re-draw the old tile of an instance of `Life` _and_ a new one, in case the creature moves:
  * draw map tile at position of dirty `Life` (this 'deletes' the visual representation of that creature from the map)
  * perform `Life.act()`
  * draw map tile of (potentially) new position of `Life`
  * draw all `GameThing` on that tile
  * draw all `Life` on that tile
