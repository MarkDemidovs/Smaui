#include "./tools/Window.h"
#include "./tools/widgets/label/Label.h"
#include <memory>

int main() {
  Window window("My Window", 800, 600);

  auto label = std::make_shared<Label>(50, 50, 200, 50, "Hello Widget!");
  auto label2 = std::make_shared<Label>(100, 100, 200, 50, "Bye Widget!");

  window.addWidget(label);
  window.addWidget(label2);

  label->setColor(0,255,0,255);

  while (window.processEvents()) {
    window.clear(255, 0, 0, 255); // blue background
    
    window.update();
  }

  return 0;
}
