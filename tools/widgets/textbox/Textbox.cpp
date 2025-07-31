#include "./Textbox.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

TextBox::TextBox(int x, int y, int w, int h)
    : Widget(x, y, w, h), focused(false), text(""), bgColor{255, 255, 255, 255}, textColor{0, 0, 0, 255} {
    font = TTF_OpenFont("./tools/creative/Arial.ttf", 18);
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    }
}

TextBox::~TextBox() {
    if (font) TTF_CloseFont(font);
}

void TextBox::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    bgColor = { r, g, b, a };
}

std::string TextBox::getText() const {
    return text;
}

void TextBox::draw(SDL_Renderer* renderer) {
    SDL_Rect rect = { x, y, width, height };
    SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
    SDL_RenderFillRect(renderer, &rect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &rect);

    renderText(renderer);
}

void TextBox::renderText(SDL_Renderer* renderer) {
    if (text.empty() || !font) return;

    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), textColor);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect dst = { x + 5, y + (height - surface->h) / 2, surface->w, surface->h };
    SDL_RenderCopy(renderer, texture, nullptr, &dst);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void TextBox::handleEvent(const SDL_Event& e) {
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        int mx = e.button.x, my = e.button.y;
        focused = (mx > x && mx < x + width && my > y && my < y + height);
    }

    if (!focused) return;

    if (e.type == SDL_TEXTINPUT) {
        text += e.text.text;
    } else if (e.type == SDL_KEYDOWN) {
        if (e.key.keysym.sym == SDLK_BACKSPACE && !text.empty()) {
            text.pop_back();
        }
    }
}
