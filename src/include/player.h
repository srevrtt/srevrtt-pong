#pragma once
#ifndef ENTITY_H
#define ENTITY_H

#include "../../deps/include/SDL.h"

class Player {
    private:
    int defaultX = 30;
    int defaultY = 245;
    int defaultVelocity = 0;

    public:

    int x = 0;
    int y = 0;
    int velocity = 0;

    void update();
    void handle(SDL_Event event, int player);
    void handleVelocity();
    void reset(int paddle);
};

#endif