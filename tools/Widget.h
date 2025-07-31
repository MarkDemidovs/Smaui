#ifndef WIDGET_H
#define WIDGET_H

#include <SDL2/SDL.h>

class Widget {
public:
    Widget(int x, int y, int w, int h)
        : x(x), y(y), width(w), height(h) {}

    virtual ~Widget() {}

    virtual void draw(SDL_Renderer* renderer) = 0;

    virtual void handleEvent(const SDL_Event& event) {}

    // Position getters/setters
    int getX() const { return x; }
    int getY() const { return y; }
    void moveTo(int newX, int newY) { x = newX; y = newY; }

    // Size getters/setters
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    void resize(int newWidth, int newHeight) { width = newWidth; height = newHeight; }

protected:
    int x, y;          // position
    int width, height; // size
};

#endif
