#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include "../include/player.h"

class Window {
    public:

    int w, h;

    void init();
    bool handleEvent(SDL_Event event);
    
    SDL_Rect draw(int x, int y, int w, int h);
    void clear();
    void display();

    void renderFont(int x, int y, int score);
    void pauseScreen();
    void endScreen(const char *message);

    void clean();
};

#endif