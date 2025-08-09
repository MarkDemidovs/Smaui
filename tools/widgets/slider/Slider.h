#pragma once
#include "../../Widget.h"
#include <functional>

class Slider : public Widget {
private:
    float minValue;
    float maxValue;
    float currentValue;

    bool dragging;
    int dragOffsetX;

    SDL_Color trackColor;
    SDL_Color thumbColor;

    std::function<void(float)> onValueChanged;

public:
    Slider(int x, int y, int width, int height, float minVal = 0.0f, float maxVal = 1.0f, float initialVal = 0.0f);

    void draw(SDL_Renderer* renderer) override;
    void handleEvent(const SDL_Event& e) override;

    void setValue(float val);
    float getValue() const;

    void setOnValueChanged(std::function<void(float)> callback);
};
