CC = g++
CPPFLAGS = -g -std=c++17 -I include -fpic
SRC_FILES = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp) $(wildcard src/*/*/*.cpp) $(wildcard src/*/*/*/*.cpp)
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

.PHONY:	linux

linux:
	$(CC) $(CPPFLAGS) -o build/test.AppImage $(SRC_FILES) $(LINKER_FLAGS)

win:
	$(CC) $(CPPFLAGS) -o build/test.exe $(SRC_FILES) -lmingw32 $(LINKER_FLAGS)

clean:
	rm build/test.AppImage
	rm build/test.exe