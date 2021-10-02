CC = g++
CPPFLAGS = -g -std=c++17 -I include -fpic
SRC_FILES = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp) $(wildcard src/*/*/*.cpp) $(wildcard src/*/*/*/*.cpp)
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

.PHONY:	build

build:
	$(CC) $(CPPFLAGS) -o build/test.AppImage $(SRC_FILES) $(LINKER_FLAGS)

remove:
	rm build/test.AppImage