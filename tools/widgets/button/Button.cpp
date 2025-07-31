#include "Button.h"
#include <SDL2/SDL_ttf.h>
#include <iostream>

Button::Button(int x, int y, int w, int h, const std::string &text, Style *s)
    : Widget(x, y, w, h), label(text), style(s) {}

void Button::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  bgColor = {r, g, b, a};
}

void Button::onClick(std::function<void()> callback) {
  clickCallback = callback;
}

void Button::draw(SDL_Renderer *renderer) {
  SDL_Rect rect = {x, y, width, height};

  // Use image style if available
  if (style) {
    SDL_Texture *bg = nullptr;
    if (pressed && style->pressed)
      bg = style->pressed;
    else if (hovering && style->hover)
      bg = style->hover;
    else if (style->background)
      bg = style->background;

    if (bg) {
      SDL_RenderCopy(renderer, bg, nullptr, &rect);
    } else {
      SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b,
                             bgColor.a);
      SDL_RenderFillRect(renderer, &rect);
    }
  } else {
    SDL_Color colorToUse = bgColor;
    if (pressed)
      colorToUse = pressColor;
    else if (hovering)
      colorToUse = hoverColor;

    SDL_SetRenderDrawColor(renderer, colorToUse.r, colorToUse.g, colorToUse.b,
                           colorToUse.a);
    SDL_RenderFillRect(renderer, &rect);
  }

  // Optional border
  /*SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderDrawRect(renderer, &rect);*/

  static bool ttfInitialized = false;
  if (!ttfInitialized) {
    if (TTF_Init() == -1) {
      std::cerr << "Failed to init TTF: " << TTF_GetError() << std::endl;
      return;
    }
    ttfInitialized = true;
  }

  // Draw the label text
  TTF_Font *font = style && style->font
                       ? style->font
                       : TTF_OpenFont("tools/creative/Default.otf", 24);
  if (!font) {
    std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    return;
  }

  SDL_Color useTextColor = style ? style->textColor : textColor;
  SDL_Surface *surface =
      TTF_RenderText_Blended(font, label.c_str(), useTextColor);
  if (!surface) {
    std::cerr << "Failed to create text surface: " << TTF_GetError()
              << std::endl;
    if (!style && font)
      TTF_CloseFont(font);
    return;
  }

  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
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

  if (!style && font) {
    TTF_CloseFont(font);
  }
}

void Button::handleEvent(const SDL_Event &e) {
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

void Button::setText(const std::string &newText) { label = newText; }
