#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <string>

class Window {
public:
    Window(const std::string& title, int width, int height);
    ~Window();

    // Main event loop - returns false when window closed
    bool processEvents();

    // Clear window with color
    void clear(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

    // Show the drawn content
    void present();

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool isOpen = true;
};

#endif
