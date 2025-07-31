#ifndef BUTTON_H
#define BUTTON_H

#include "../../Widget.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <functional>
#include <string>

class Button : public Widget {
public:
    Button(int x, int y, int w, int h, const std::string& text, TTF_Font* font);
    void draw(SDL_Renderer* renderer) override;
    void handleEvent(const SDL_Event& e) override;

    void setOnClick(std::function<void()> callback);

private:
    enum class State { Normal, Hovered, Pressed };
    State state = State::Normal;

    std::string text;
    TTF_Font* font;
    SDL_Texture* texture = nullptr;
    SDL_Color textColor = { 255, 255, 255, 255 };

    std::function<void()> onClick;

    void updateTexture(SDL_Renderer* renderer);
};

#endif
