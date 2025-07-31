#include "Button.h"
#include <SDL2/SDL_ttf.h>
#include <iostream>

Button::Button(int x, int y, int w, int h, const std::string& text)
    : Widget(x, y, w, h), label(text) {}

void Button::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    bgColor = { r, g, b, a };
}

void Button::onClick(std::function<void()> callback) {
    clickCallback = callback;
}

void Button::draw(SDL_Renderer* renderer) {
    SDL_Color colorToUse = bgColor;
    if (pressed) colorToUse = pressColor;
    else if (hovering) colorToUse = hoverColor;

    SDL_SetRenderDrawColor(renderer, colorToUse.r, colorToUse.g, colorToUse.b, colorToUse.a);
    SDL_Rect rect = { x, y, width, height };
    SDL_RenderFillRect(renderer, &rect);

    // Optional: border
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &rect);

    // === Draw the label text ===

    static TTF_Font* font = nullptr;
    if (!font) {
        font = TTF_OpenFont("tools/creative/Arial.ttf", 24);
        if (!font) {
            std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
            return;
        }
    }

    SDL_Surface* surface = TTF_RenderText_Blended(font, label.c_str(), {255, 255, 255, 255}); // white text
    if (!surface) {
        std::cerr << "Failed to create text surface: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        std::cerr << "Failed to create text texture: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(surface);
        return;
    }

    // Center the text inside the button
    int textW = surface->w;
    int textH = surface->h;
    SDL_FreeSurface(surface);

    SDL_Rect textRect;
    textRect.w = textW;
    textRect.h = textH;
    textRect.x = x + (width - textW) / 2;
    textRect.y = y + (height - textH) / 2;

    SDL_RenderCopy(renderer, texture, nullptr, &textRect);
    SDL_DestroyTexture(texture);
}


void Button::handleEvent(const SDL_Event& e) {
    if (e.type == SDL_MOUSEMOTION) {
        int mx = e.motion.x;
        int my = e.motion.y;
        hovering = (mx >= x && mx <= x + width && my >= y && my <= y + height);
    }

    if (e.type == SDL_MOUSEBUTTONDOWN && hovering) {
        pressed = true;
    }

    if (e.type == SDL_MOUSEBUTTONUP) {
        if (pressed && hovering && clickCallback) {
            clickCallback();
        }
        pressed = false;
    }
}

void Button::setText(const std::string& newText) {
    label = newText;
}