#include "Label.h"
#include <SDL2/SDL_ttf.h>
#include <iostream>

Label::Label(int x, int y, int w, int h, const std::string& text)
    : Widget(x, y, w, h), text(text) {

    if (TTF_WasInit() == 0) {
        if (TTF_Init() == -1) {
            std::cerr << "Failed to init SDL_ttf: " << TTF_GetError() << std::endl;
            exit(1);
        }
    }
}

void Label::draw(SDL_Renderer* renderer) {
    
    TTF_Font* font = TTF_OpenFont("tools/creative/Default.otf", 24);
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Color color = textColor; 

    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
    if (!surface) {
        std::cerr << "Failed to create text surface: " << TTF_GetError() << std::endl;
        TTF_CloseFont(font);
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        std::cerr << "Failed to create text texture: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(surface);
        TTF_CloseFont(font);
        return;
    }

    SDL_Rect dstRect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}

void Label::setText(const std::string& newText) {
    text = newText;
}

void Label::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    textColor = {r, g, b, a};
}