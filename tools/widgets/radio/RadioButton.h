#pragma once
#include "../../Widget.h"
#include <string>

class RadioButtonGroup;  // forward declaration

class RadioButton : public Widget {
private:
    bool selected;
    std::string label;
    RadioButtonGroup* group;

    SDL_Color circleColor;
    SDL_Color dotColor;
    SDL_Color labelColor;

public:
    RadioButton(int x, int y, int diameter = 20, const std::string& labelText = "");

    void draw(SDL_Renderer* renderer) override;
    void handleEvent(const SDL_Event& e) override;

    void setSelected(bool value);
    bool isSelected() const;

    void setLabel(const std::string& text);
    void setGroup(RadioButtonGroup* grp);
};
