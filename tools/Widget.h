#ifndef WIDGET_H
#define WIDGET_H

#include <SDL2/SDL.h>

class Widget {
public:
    Widget(int x, int y, int w, int h)
        : x(x), y(y), width(w), height(h) {}

    virtual ~Widget() {}

    virtual void draw(SDL_Renderer* renderer) = 0;

    // Handle SDL events, can be overridden by subclasses
    virtual void handleEvent(const SDL_Event& event) {}

protected:
    int x, y;       // position
    int width, height; // size
};

#endif
