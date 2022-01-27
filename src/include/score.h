#pragma once
#ifndef SCORE_H
#define SCORE_H

#include "window.h"

class Score {
    private:
    public:

    int x = 200;
    int score = 0;

    void add(Window window);
    void update(Window window);
};

#endif