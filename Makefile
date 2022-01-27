all:
	g++ -std=c++14 -g -Wall ./src/*.cpp -I deps/include -L deps/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -o debug/bin/game.o
	./debug/bin/game.o