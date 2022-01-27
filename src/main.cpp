#include <iostream>
#include <string>

#include "../deps/include/SDL.h"
#include "include/game.h"

int main(int argc, char *argv[]) {
    init();

    bool running = true;
    while (running) {
        running = run();
    }

    cleanup();

    return 0;
}