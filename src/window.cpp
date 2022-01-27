#include <iostream>
#include <string>

#include "../deps/include/SDL.h"
#include "../deps/include/SDL_ttf.h"
#include "../deps/include/SDL_image.h"

#include "include/window.h"
#include "include/player.h"

SDL_Window *window;
SDL_Renderer *renderer;

bool rendering = true;

TTF_Font *font;

void Window::init() {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();

    window = SDL_CreateWindow(
        "C++ Pong Remake by Srevrtt",
        SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED,
        this->w,
        this->h,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cout << "Failed to create window\n" << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    if (!renderer) {
        std::cout << "Failed to create renderer\n" << std::endl;
    }

    font = TTF_OpenFont("res/gfx/font.ttf", 25);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

bool Window::handleEvent(SDL_Event event) {
    if (event.type == SDL_QUIT) {
        return false;
    }

    return true;
}

// render the font and convert the score to a char
void Window::renderFont(int x, int y, int score) {
    if (rendering == true) {
        SDL_Color color = {255, 255, 255};

        std::string tmp = std::to_string(score);
        const char *num_char = tmp.c_str();

        SDL_Surface *surface = TTF_RenderText_Solid(font, num_char, color);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

        int texW = 0;
        int texH = 0;
        
        SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
        SDL_Rect dstrect = {x, y, texW, texH};
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
    }
}

// render
SDL_Rect Window::draw(int x, int y, int w, int h) {
    SDL_Rect rect;
    
    if (rendering == true) {        
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &rect);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }

    return rect;
}

// clear the renderer
void Window::clear() {
    SDL_RenderClear(renderer);
}

// display everything in the window
void Window::display() {
    SDL_RenderPresent(renderer);
}

// pause the game
void Window::pauseScreen() {
    if (rendering == true) {
        rendering = false;

        SDL_Surface *surface = IMG_Load("res/gfx/pause.png");
        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);

        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
    } else {
        rendering = true;
    }
}

void Window::endScreen(const char *message) {
    rendering = false;
    SDL_Color color = {255, 255, 255};
    
    SDL_Surface *surface = TTF_RenderText_Solid(font, message, color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

    int texW = 0;
    int texH = 0;
    
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect = {90, 270, texW, texH};
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

// clear everything when we're done
void Window::clean() {
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}