CC = g++
CFLAGS = -Wall -g
CLIBS = -lcurses -lm

BUILD_DIR = build/
SRC_DIR = src/
TEST_DIR = tests/

# master commands
all: clean roguelike
roguelike: lifeforms maphandlers timekeeper.o main.o livingbeings.o
	$(CC) $(CFLAGS) -o roguelike $(BUILD_DIR)main.o \
		$(BUILD_DIR)gameobject.o $(BUILD_DIR)life.o $(BUILD_DIR)player.o $(BUILD_DIR)mouse.o $(BUILD_DIR)frog.o $(BUILD_DIR)critter.o $(BUILD_DIR)generator.o \
		$(BUILD_DIR)livingbeings.o \
		$(BUILD_DIR)timekeeper.o \
		$(BUILD_DIR)mapdata.o $(BUILD_DIR)mapgenerator.o $(BUILD_DIR)mapinterface.o $(BUILD_DIR)mapwindow.o \
		$(CLIBS)
main.o:
	$(CC) $(CFLAGS) -o $(BUILD_DIR)main.o -c $(SRC_DIR)main.cpp
clean:
	rm -f $(BUILD_DIR)*.o
	rm -f roguelike

# Helpers
generator.o:
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)Generator.cpp
timekeeper.o:
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)Timekeeper.cpp

# Structures
livingbeings.o: life.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)Structs/LivingBeings.cpp

# Life-Forms
lifeforms: generator.o frog.o mouse.o player.o

frog.o: critter.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)GameObjects/Life/Critter/Frog.cpp
mouse.o: critter.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)GameObjects/Life/Critter/Mouse.cpp
critter.o: life.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)GameObjects/Life/Critter/Critter.cpp
player.o: life.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)GameObjects/Life/Player.cpp
life.o: gameobject.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)GameObjects/Life/Life.cpp
gameobject.o: generator.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)GameObjects/GameObject.cpp

# Map Handlers
maphandlers: mapdata.o mapgenerator.o mapinterface.o mapwindow.o

mapdata.o: livingbeings.o
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)Map/MapData.cpp
mapgenerator.o:
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)Map/MapGenerator.cpp
mapinterface.o:
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)Map/MapInterface.cpp
mapwindow.o:
	$(CC) $(CFLAGS) -o $(BUILD_DIR)$@ -c $(SRC_DIR)Map/MapWindow.cpp
