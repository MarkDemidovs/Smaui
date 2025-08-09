#include "Slider.h"
#include <algorithm>

Slider::Slider(int x, int y, int width, int height, float minVal, float maxVal, float initialVal)
    : Widget(x, y, width, height),
      minValue(minVal),
      maxValue(maxVal),
      currentValue(initialVal),
      dragging(false),
      dragOffsetX(0) {

    trackColor = { 100, 100, 100, 255 };
    thumbColor = { 50, 150, 50, 255 };
}

void Slider::draw(SDL_Renderer* renderer) {
    // Draw track (a horizontal rounded rect or rectangle)
    SDL_Rect trackRect = { x, y + height / 2 - 4, width, 8 };
    SDL_SetRenderDrawColor(renderer, trackColor.r, trackColor.g, trackColor.b, trackColor.a);
    SDL_RenderFillRect(renderer, &trackRect);

    // Calculate thumb position based on current value
    float normalized = (currentValue - minValue) / (maxValue - minValue);
    int thumbX = x + (int)(normalized * (width - height));
    SDL_Rect thumbRect = { thumbX, y, height, height };

    // Draw thumb (circle or square)
    SDL_SetRenderDrawColor(renderer, thumbColor.r, thumbColor.g, thumbColor.b, thumbColor.a);
    SDL_RenderFillRect(renderer, &thumbRect);
}

void Slider::handleEvent(const SDL_Event& e) {
    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
        int mx = e.button.x;
        int my = e.button.y;

        float normalized = (currentValue - minValue) / (maxValue - minValue);
        int thumbX = x + (int)(normalized * (width - height));

        SDL_Rect thumbRect = { thumbX, y, height, height };
        if (mx >= thumbRect.x && mx <= thumbRect.x + thumbRect.w &&
            my >= thumbRect.y && my <= thumbRect.y + thumbRect.h) {
            dragging = true;
            dragOffsetX = mx - thumbX;
        }
    } else if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT) {
        dragging = false;
    } else if (e.type == SDL_MOUSEMOTION && dragging) {
        int mx = e.motion.x;
        // Calculate new thumb position
        int newThumbX = mx - dragOffsetX;
        newThumbX = std::max(x, std::min(newThumbX, x + width - height));

        // Update currentValue based on thumb position
        float normalized = (float)(newThumbX - x) / (float)(width - height);
        setValue(minValue + normalized * (maxValue - minValue));
    }
}

void Slider::setValue(float val) {
    float clamped = std::max(minValue, std::min(val, maxValue));
    if (clamped != currentValue) {
        currentValue = clamped;
        if (onValueChanged) onValueChanged(currentValue);
    }
}

float Slider::getValue() const {
    return currentValue;
}

void Slider::setOnValueChanged(std::function<void(float)> callback) {
    onValueChanged = callback;
}
