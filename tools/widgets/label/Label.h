#ifndef LABEL_H
#define LABEL_H

#include "../../Widget.h"
#include <string>

class Label : public Widget {
public:
    Label(int x, int y, int w, int h, const std::string& text);

    void draw(SDL_Renderer* renderer) override;

    void setText(const std::string& text);

    void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

private:
    std::string text;
    SDL_Color textColor = {255, 255, 255, 255};
};

#endif
