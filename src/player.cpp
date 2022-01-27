#include <iostream>
#include <string>

#include "include/player.h"

// whenever the player moves, we move the paddle
void Player::update() {
    this->y -= this->velocity * 3;
}

// whenever a player presses a specific key, we move the paddle
void Player::handle(SDL_Event event, int player) {
    if (player == 1) { // if player 1 presses a key
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_w: // W key
                    if (this->y > 15) {
                        this->velocity = 1.5;
                    } else {
                        this->velocity = 0;
                        this->y = 15;
                    }

                    break;
                case SDLK_s: // S key
                    if (this->y < 455) {
                        this->velocity = -1.5;
                    } else {
                        this->velocity = 0;
                    }

                    break;
            }
        } else if (event.type == SDL_KEYUP) {
            switch (event.key.keysym.sym) {
                case SDLK_w: 
                    this->velocity = 0;
                    break;
                case SDLK_s: 
                    this->velocity = 0;
                    break;
            }
        }
    } else if (player == 2) { // if player 2 presses a key
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP: // up arrow key
                    if (this->y > 15) {
                        this->velocity = 1.5;
                    } else {
                        this->velocity = 0;
                        this->y = 15;
                    }

                    break;
                case SDLK_DOWN: // down arrow key
                    if (this->y < 455) {
                        this->velocity = -1.5;
                    } else {
                        this->velocity = 0;
                    }

                    break;
            }
        } else if (event.type == SDL_KEYUP) {
            switch (event.key.keysym.sym) {
                case SDLK_UP: 
                    this->velocity = 0;
                    break;
                case SDLK_DOWN: 
                    this->velocity = 0;
                    break;
            }
        }
    }
}

// barriers
void Player::handleVelocity() {
    if (this->y < 15) {
        this->velocity = 0; // stop the player
    }

    if (this->y > 455) {
        this->velocity = 0; // stop the player
    }
}

// when the round ends
void Player::reset(int paddle) {
    this->y = this->defaultY; 
    this->velocity = this->defaultVelocity;

    if (paddle == 0) {
        this->x = this->defaultX;
    } else if (paddle == 1) {
        this->x = 755;
    }
}