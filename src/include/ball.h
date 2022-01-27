#pragma once 
#ifndef BALL_H
#define BALL_H

#include "player.h"

class Ball {
    private:
    int defaultX = 392;
    int defaultY = 292;

    public:

    void update();
    void intersects(int player);
    void reset();
    void handleEvent(SDL_Event event);
    
    void handleInteractions(SDL_Rect player1Obj, SDL_Rect player2Obj, SDL_Rect ballObj, Player player1, Player player2);

    int x = 392;
    int y = 292;

    int velocity = 1;
    int yVelocity = -1;

    int state = 0;
};

#endif