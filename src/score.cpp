#include <iostream>
#include <string>
#include <sstream>

#include "../deps/include/SDL.h"

#include "include/score.h"
#include "include/window.h"

void Score::update(Window window) {
    window.renderFont(this->x, 25, this->score);
    std::cout << this->score << std::endl;

    if (this->score == 10) {
        // TODO: add end screen
    }
}