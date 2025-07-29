#include <SDL2/SDL.h>

class Widget {
public:
    int x, y, width, height;
    bool visible;

    Widget(int x, int y, int w, int h) 
      : x(x), y(y), width(w), height(h), visible(true) {}

    virtual ~Widget() = default;

    virtual void render(SDL_Renderer* renderer) = 0; // pure virtual
    virtual void update(SDL_Event& event) {} // optional override
};
