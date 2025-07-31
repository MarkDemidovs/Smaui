#ifndef BUTTON_H
#define BUTTON_H

#include "../../Widget.h"
#include <functional>
#include <string>

class Button : public Widget {
public:
    Button(int x, int y, int w, int h, const std::string& text);

    void draw(SDL_Renderer* renderer) override;
    void handleEvent(const SDL_Event& e) override;

    void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    void onClick(std::function<void()> callback);

private:
    std::string label;
    SDL_Color bgColor = { 100, 100, 100, 255 };
    SDL_Color hoverColor = { 150, 150, 150, 255 };
    SDL_Color pressColor = { 200, 200, 200, 255 };
    SDL_Color textColor = { 255, 255, 255, 255 };

    bool hovering = false;
    bool pressed = false;

    std::function<void()> clickCallback = nullptr;
};

#endif
