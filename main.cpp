#include "./tools/Window.h"

int main() {
    Window window("My SDL2 Window Class", 800, 600);

    while (window.processEvents()) {
        window.clear(0, 128, 255, 255); // blue background
        // TODO: draw widgets here later
        window.present();
    }

    return 0;
}
