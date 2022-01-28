#include <iostream>
#include <string>
#include <sstream>

#include "../deps/include/SDL.h"

#include "include/window.h"
#include "include/player.h"
#include "include/ball.h"
#include "include/score.h"

#define FRAME_DELAY (1000 / 60)

int player1Score;
int player2Score;
int displayCount;

Uint32 frameStart;
Uint32 frameTime;

Window game;
Player player1;
Player player2;
Ball ball;

SDL_Event event;

bool running;

int currentPaddle;
bool paused = false;

void init() {
    game.w = 800;
    game.h = 600;

    game.init();
    player1.reset(0);
    player2.reset(1);
    
    player1Score = 0;
    player2Score = 0;
    displayCount = 0;
}

bool run() {
    frameStart = SDL_GetTicks();
    game.clear(); // clear the current frame

    bool running = SDL_PollEvent(&event);
    running = game.handleEvent(event); // handle the event (e.g. keyboard and mouse events)

    // handle the movement of the paddles

    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_ESCAPE:
                if (paused == false) {
                    paused = true;

                    game.pauseScreen();
                }

                break;
            case SDLK_SPACE:
                if (paused == true) {
                    paused = false;

                    game.pauseScreen();
                }

                break;
        }
    }

    SDL_Rect ballObj;
    SDL_Rect player1Obj; 
    SDL_Rect player2Obj;
    
    if (paused == false) {
        ballObj = game.draw(ball.x, ball.y, 15, 15);
        player1Obj = game.draw(player1.x, player1.y, 15, 110);
        player2Obj = game.draw(player2.x, player2.y, 15, 110);
        
        player1.handle(event, 1);
        player2.handle(event, 2);
        ball.handleEvent(event);

        game.renderFont(200, 25, player1Score);
        game.renderFont(600, 25, player2Score);

        if (ball.state == 1) {

            player1.update();
            player2.update();
            ball.update();

            player1.handleVelocity();
            player2.handleVelocity();

            Score score1;
            Score score2;
            score2.x = 600;

            if (SDL_HasIntersection(&ballObj, &player1Obj)) {
                ball.intersects(1);
                ball.update();

                currentPaddle = 1;
            } else if (SDL_HasIntersection(&ballObj, &player2Obj)) {
                ball.intersects(2);
                ball.update();

                currentPaddle = 2;

                game.renderFont(200, 25, player1Score);
                game.renderFont(600, 25, player2Score);
            }

            if (ball.y <= 0) {
                if (currentPaddle == 1) {
                    
                    ball.velocity = -1.5;
                } else {
                    ball.velocity = 1.5;
                }

                ball.yVelocity = -ball.yVelocity;
            } else if (ball.y >= 585) {
                if (currentPaddle == 1) {
                    ball.velocity = -1.5;
                } else {
                    ball.velocity = 1.5;
                }
                
                ball.yVelocity = -ball.yVelocity;
            }

            if (ball.x <= 0) {
                player1.reset(0);
                player2.reset(1);

                player2Score++;

                ball.reset();
            } else if (ball.x >= 785) {
                player1.reset(0);
                player2.reset(1);

                player1Score++;

                ball.reset();
            }

            if (ball.state == 1) {
                // update the velocity
                player1.update();
                player2.update();
                
                // if the paddle tries to cross the barriers
                player1.handleVelocity();
                player2.handleVelocity();

                ball.update();
            }
        }

        if (player1Score == 10) {
            game.endScreen("Player1 has won the game!");
        } else if (player2Score == 10) {
            game.endScreen("Player2 has won the game!");
        }

        // render the objects to the screen
        game.display();

    }

    // limiting FPS
    frameTime = SDL_GetTicks() - frameStart;
    if (FRAME_DELAY > frameTime) {
        SDL_Delay(FRAME_DELAY - frameTime);
    }
    return running;
}

void cleanup() {
    game.clean();
}