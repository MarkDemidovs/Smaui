#include "Style.h"
#include "SDL2/SDL_image.h"
#include <iostream>

Style::~Style() {
    if (background) SDL_DestroyTexture(background);
    if (hover) SDL_DestroyTexture(hover);
    if (pressed) SDL_DestroyTexture(pressed);
    if (font) TTF_CloseFont(font);
}

static SDL_Texture* loadTexture(SDL_Renderer* r, const std::string& path) {
    SDL_Surface* surface = IMG_Load(path.c_str());
    if (!surface) {
        std::cerr << "IMG_Load failed: " << IMG_GetError() << std::endl;
        return nullptr;
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface(r, surface);
    SDL_FreeSurface(surface);
    return tex;
}

Style* loadStyle(SDL_Renderer* renderer, const std::string& basePath) {
    Style* style = new Style();
    style->background = loadTexture(renderer, basePath + "_idle.png");
    style->hover = loadTexture(renderer, basePath + "_hover.png");
    style->pressed = loadTexture(renderer, basePath + "_pressed.png");

    style->textColor = {0, 0, 0, 255};
    style->padding = 12;

    style->font = TTF_OpenFont("tools/creative/Default.otf", 24);
    if (!style->font) {
        std::cerr << "TTF_OpenFont failed: " << TTF_GetError() << std::endl;
    }

    return style;
}
