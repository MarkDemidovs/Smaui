#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include <memory>

// Forward declare Widget
class Widget;

class Window {
public:
    Window(const std::string& title, int width, int height);
    ~Window();

    // Main event loop - returns false when window closed
    bool processEvents();

    // Clear window with color
    void clear(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

    // Show the drawn content
    void update();

    // Add widget to the window
    void addWidget(std::shared_ptr<Widget> widget);

    // Get SDL_Renderer (for widgets to draw)
    SDL_Renderer* getRenderer() const;

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool isOpen = true;

    std::vector<std::shared_ptr<Widget>> widgets;  // store widgets
};

#endif
