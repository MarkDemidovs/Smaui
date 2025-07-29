#include "./tools/Window.h"

int main() {
  Window window("My Window", 800, 600);

  while (window.processEvents()) {
    window.clear(255, 0, 0, 255); // blue background
    // TODO: draw widgets here later
    window.update();
  }

  return 0;
}
