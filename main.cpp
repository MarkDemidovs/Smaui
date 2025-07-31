#include "./tools/Window.h"
#include "./tools/widgets/label/Label.h"
#include "./tools/widgets/button/Button.h"
#include <memory>
#include <iostream>

int main() {
  Window window("My Window", 800, 600);


  auto label = std::make_shared<Label>(50, 50, 200, 50, "I am above!");
  auto label2 = std::make_shared<Label>(50, 100, 200, 50, "I am below!");

  auto button = std::make_shared<Button>(50, 150, 200, 50, "Click me!");

    button->onClick([label]() {
        std::cout << "Button clicked!\n";
        label->setColor(255, 255, 0, 255);
    });

  window.addWidget(label);
  window.addWidget(label2);

  window.addWidget(button);

  label->setColor(0,255,0,255);

  while (window.processEvents()) {
    window.clear(255, 0, 0, 255); // blue background

    window.update();
  }

  return 0;
}
