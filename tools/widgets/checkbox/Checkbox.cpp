#include "Checkbox.h"
#include <SDL2/SDL.h>

Checkbox::Checkbox(int x, int y, int size, const std::string& labelText)
    : Widget(x, y, size, size), checked(false), label(labelText) {
    boxColor = { 255, 255, 255, 255 };      // white box
    checkColor = { 0, 0, 0, 255 };      // black checkmark
    labelColor = { 0, 0, 0, 255 };          // black text
}

void Checkbox::draw(SDL_Renderer* renderer) {
    // Draw box background
    SDL_Rect boxRect = { x, y, width, height };
    SDL_SetRenderDrawColor(renderer, boxColor.r, boxColor.g, boxColor.b, boxColor.a);
    SDL_RenderFillRect(renderer, &boxRect);

    // Draw box border
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &boxRect);

    // Draw checkmark if checked
    if (checked) {
        SDL_SetRenderDrawColor(renderer, checkColor.r, checkColor.g, checkColor.b, checkColor.a);
        // Simple cross inside box (can be improved with texture or lines)
        SDL_RenderDrawLine(renderer, x + 4, y + 4, x + width - 4, y + height - 4);
        SDL_RenderDrawLine(renderer, x + 4, y + height - 4, x + width - 4, y + 4);
    }

    // Draw label text (simple placeholder; TBA?)
    if (!label.empty()) {

    }
}

void Checkbox::handleEvent(const SDL_Event& e) {
    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
        int mx = e.button.x, my = e.button.y;
        if (mx > x && mx < x + width && my > y && my < y + height) {
            checked = !checked;
        }
    }
}

void Checkbox::setChecked(bool value) {
    checked = value;
}

bool Checkbox::isChecked() const {
    return checked;
}

void Checkbox::setLabel(const std::string& text) {
    label = text;
}
