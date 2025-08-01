#pragma once
#include "../../Widget.h"
#include <string>

class Checkbox : public Widget {
private:
    bool checked;
    std::string label;
    SDL_Color boxColor;
    SDL_Color checkColor;
    SDL_Color labelColor;

public:
    Checkbox(int x, int y, int size = 20, const std::string& labelText = "");

    void draw(SDL_Renderer* renderer) override;
    void handleEvent(const SDL_Event& e) override;

    void setChecked(bool value);
    bool isChecked() const;

    void setLabel(const std::string& text);
};
