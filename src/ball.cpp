#include <iostream>
#include <string>

#include <cstdlib>
#include <ctime>

#include "../deps/include/SDL.h"
#include "include/ball.h"

int previousRandom;
int random;

// make sure the ball moves
void Ball::update() {
    this->y -= this->yVelocity;
    this->x -= this->velocity * 2;
}

// when the ball hits a player
void Ball::intersects(int player) {
    if (player == 1) {
        this->velocity = -1.5;

        previousRandom = random;
        random = rand() % 5;

        if (random > 3) {
            std::cout << random << std::endl; 
            this->velocity = -(random - 3);
        }
        
        while (previousRandom == random) {
            random = rand() % 5;

            if (random > 3) {
                std::cout << random << std::endl; 
                this->velocity = -(random - 3);
            }
        }
        
    } else {
        this->velocity = 1.5;
    }
}

// when a round is finished
void Ball::reset() {
    this->y = this->defaultY;
    this->x = this->defaultX;

    this->state = 0;
    this->velocity = 1;
    this->yVelocity = -1;
}

// setting the state for when someone starts the game
void Ball::handleEvent(SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_q:

            if (this->state == 0) {
                this->state = 1;
            }

            break;
        }
    }
}