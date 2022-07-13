CC = g++
CFLAGS = -Wall -g
CLIBS = -lcurses -lm

BUILD_DIR = build/
SRC_DIR = src/
TEST_DIR = tests/

# master commands
all: clean roguelike
roguelike: lifeforms maphandlers timekeeper.o logger.o main.o livingbeings.o
	$(CC) $(CFLAGS) -o roguelike $(BUILD_DIR)main.o \
		$(BUILD_DIR)objectstore.o $(BUILD_DIR)gameobject.o $(BUILD_DIR)life.o $(BUILD_DIR)player.o $(BUILD_DIR)mouse.o $(BUILD_DIR)frog.o $(BUILD_DIR)critter.o \
		$(BUILD_DIR)livingbeings.o \
		$(BUILD_DIR)generator.o $(BUILD_DIR)timekeeper.o $(BUILD_DIR)logger.o \
		$(BUILD_DIR)tilestore.o $(BUILD_DIR)mapgenerator.o $(BUILD_DIR)mapwindow.o \
		$(CLIBS)
main.o:
	$(CC) $(CFLAGS) -o $(BUILD_DIR)main.o -c $(SRC_DIR)main.cpp
clean:
	rm -f $(BUILD_DIR)*.o
	rm -f roguelike

# Helpers
generator.o:
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)Helpers/Generator.cpp
timekeeper.o: objectstore.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)Helpers/Timekeeper.cpp
logger.o:
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)Helpers/Logger.cpp

# Structures
livingbeings.o: life.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)Structs/LivingBeings.cpp

# Life-Forms
lifeforms: frog.o mouse.o player.o objectstore.o

objectstore.o: livingbeings.o player.o life.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)GameObjects/ObjectStore.cpp

frog.o: critter.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)GameObjects/Life/Critter/Frog.cpp
mouse.o: critter.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)GameObjects/Life/Critter/Mouse.cpp
critter.o: life.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)GameObjects/Life/Critter/Critter.cpp
player.o: life.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)GameObjects/Life/Player.cpp
life.o: gameobject.o tilestore.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)GameObjects/Life/Life.cpp
gameobject.o: generator.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)GameObjects/GameObject.cpp

# Map Handlers
maphandlers: tilestore.o mapgenerator.o mapwindow.o

tilestore.o:
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)Map/TileStore.cpp
mapgenerator.o: tilestore.o objectstore.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)Map/MapGenerator.cpp
mapwindow.o: tilestore.o objectstore.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)Map/MapWindow.cpp

# tests
tests: test_logging test_time_raw test_time_integrated
test_logging: logger.o
	$(CC) $(CFLAGS) -o $(TEST_DIR)logging $(BUILD_DIR)logger.o $(TEST_DIR)logging.cpp $(CLIBS)
test_time_raw:
	$(CC) $(CFLAGS) -o $(TEST_DIR)time $(TEST_DIR)time.cpp $(CLIBS)
test_time_integrated: frog.o mouse.o tilestore.o timekeeper.o
	$(CC) $(CFLAGS) -o $(TEST_DIR)time2 \
		$(BUILD_DIR)objectstore.o $(BUILD_DIR)livingbeings.o \
		$(BUILD_DIR)gameobject.o $(BUILD_DIR)life.o $(BUILD_DIR)critter.o \
		$(BUILD_DIR)player.o $(BUILD_DIR)frog.o $(BUILD_DIR)mouse.o \
		$(BUILD_DIR)generator.o $(BUILD_DIR)tilestore.o $(BUILD_DIR)timekeeper.o \
		$(TEST_DIR)time_integrated.cpp $(CLIBS)
