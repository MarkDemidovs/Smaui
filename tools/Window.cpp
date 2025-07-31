#include "Window.h"
#include "./Widget.h"  // include Widget base class

#include <iostream>

Window::Window(const std::string& title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << "\n";
        exit(1);
    }

    window = SDL_CreateWindow(title.c_str(),
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              width, height,
                              SDL_WINDOW_SHOWN);

    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << "\n";
        SDL_Quit();
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1,
                                  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!renderer) {
        SDL_DestroyWindow(window);
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << "\n";
        SDL_Quit();
        exit(1);
    }
}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Window::processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isOpen = false;
        }

        // Forward event to widgets (we'll add this soon)
        for (auto& widget : widgets) {
            widget->handleEvent(event);
        }
    }
    return isOpen;
}

void Window::clear(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderClear(renderer);
}

void Window::update() {
    // Draw widgets
    for (auto& widget : widgets) {
        widget->draw(renderer);
    }

    SDL_RenderPresent(renderer);
}

void Window::addWidget(std::shared_ptr<Widget> widget) {
    widgets.push_back(widget);
}

SDL_Renderer* Window::getRenderer() const {
    return renderer;
}
