#ifndef STYLE_H
#define STYLE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

struct Style {
    SDL_Texture* background = nullptr;
    SDL_Texture* hover = nullptr;
    SDL_Texture* pressed = nullptr;

    SDL_Color textColor = {0, 0, 0, 255};
    TTF_Font* font = nullptr;

    int padding = 8;

    ~Style(); // clean up textures and font
};

Style* loadStyle(SDL_Renderer* renderer, const std::string& basePath);

#endif
