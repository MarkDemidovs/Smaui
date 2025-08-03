#include "RadioButton.h"
#include "RadioButtonGroup.h"
#include <SDL2/SDL.h>

RadioButton::RadioButton(int x, int y, int diameter, const std::string& labelText)
    : Widget(x, y, diameter, diameter), selected(false), label(labelText), group(nullptr) {
    circleColor = { 200, 200, 200, 255 };
    dotColor = { 0, 0 , 200, 255 };
    labelColor = { 0, 0, 0, 255 };
}

void RadioButton::draw(SDL_Renderer* renderer) {
    // Draw outer circle
    int centerX = x + width / 2;
    int centerY = y + height / 2;
    int radius = width / 2 - 1;

    // Draw circle (simple approximation)
    SDL_SetRenderDrawColor(renderer, circleColor.r, circleColor.g, circleColor.b, circleColor.a);
    for (int w = 0; w < 2; ++w) { // thickness
        for (int angle = 0; angle < 360; angle++) {
            int dx = (int)(radius * cos(angle * M_PI / 180));
            int dy = (int)(radius * sin(angle * M_PI / 180));
            SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
        }
        radius -= 1;
    }

    // Draw filled dot if selected
    if (selected) {
        SDL_SetRenderDrawColor(renderer, dotColor.r, dotColor.g, dotColor.b, dotColor.a);
        int innerRadius = width / 4;
        for (int w = 0; w < innerRadius; ++w) {
            for (int angle = 0; angle < 360; angle++) {
                int dx = (int)((innerRadius - w) * cos(angle * M_PI / 180));
                int dy = (int)((innerRadius - w) * sin(angle * M_PI / 180));
                SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
            }
        }
    }

    // Draw label text - placeholder, integrate your font rendering here

}

void RadioButton::handleEvent(const SDL_Event& e) {
    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
        int mx = e.button.x, my = e.button.y;
        if (mx >= x && mx <= x + width && my >= y && my <= y + height) {
            if (group) {
                group->setSelected(this);
            } else {
                selected = true;
            }
        }
    }
}

void RadioButton::setSelected(bool value) {
    selected = value;
}

bool RadioButton::isSelected() const {
    return selected;
}

void RadioButton::setLabel(const std::string& text) {
    label = text;
}

void RadioButton::setGroup(RadioButtonGroup* grp) {
    group = grp;
}
