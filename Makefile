all:
	g++ -std=c++14 -g -Wall ./src/*.cpp ./bin/*.dll -I deps/include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -mwindows -o bin/game
	./bin/game.exe
