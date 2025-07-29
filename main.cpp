#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <iostream>

int main(int argc, char* argv[]) {
    // Initialize SDL2 video system
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Error initializing SDL2: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a window (800x600)
    SDL_Window* window = SDL_CreateWindow("SDL2 Window", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    
    if (!window) {
        std::cerr << "Error creating window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Creating a renderer (Required on Hyprland to show up!)
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
    SDL_RENDERER_ACCELERATED ||  SDL_RENDERER_PRESENTVSYNC);

    if(!renderer) {
        std::cerr << "SDL_CreateRenderer Error:" << SDL_GetError() << '\n';
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Drawing Colour
    SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
    // Clearing The Screen with Colour
    SDL_RenderClear(renderer);
    // Show the updated window content
    SDL_RenderPresent(renderer);


    // Wait for 3 seconds
    SDL_Delay(3000);

    // Clean up and quit SDL2
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
