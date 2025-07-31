// Lesson 6: Textbox (Single-Line Text Input Widget)

// File: ./tools/widgets/textbox/TextBox.h
#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "../../Widget.h"
#include <SDL2/SDL_ttf.h>
#include <string>

class TextBox : public Widget {
public:
    TextBox(int x, int y, int w, int h);
    ~TextBox();

    void draw(SDL_Renderer* renderer) override;
    void handleEvent(const SDL_Event& e) override;
    void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    std::string getText() const;

private:
    std::string text;
    bool focused;
    SDL_Color bgColor;
    SDL_Color textColor;
    TTF_Font* font;
    void renderText(SDL_Renderer* renderer);
};

#endif // TEXTBOX_H
