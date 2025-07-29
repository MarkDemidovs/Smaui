#include <string>
#include <./SDL2/SDL_ttf.h>
#include "../Widget.h"

class Label : public Widget {
public:
    std::string text;
    SDL_Color color;
    TTF_Font* font;

    Label(int x, int y, const std::string& text, TTF_Font* font, SDL_Color color)
      : Widget(x, y, 0, 0), text(text), font(font), color(color) {
        // Width and height can be computed from text size
        int textW, textH;
        TTF_SizeText(font, text.c_str(), &textW, &textH);
        width = textW;
        height = textH;
    }

    void render(SDL_Renderer* renderer) override {
        SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_Rect destRect = { x, y, surface->w, surface->h };
        SDL_FreeSurface(surface);

        SDL_RenderCopy(renderer, texture, nullptr, &destRect);
        SDL_DestroyTexture(texture);
    }
};
