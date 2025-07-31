#include "./tools/Window.h"
#include "./tools/widgets/button/Button.h"
#include "./tools/widgets/label/Label.h"
#include "./tools/widgets/panel/Panel.h"
#include <iostream>
#include <memory>

int main() {
  Window window("My Window", 800, 600);

  auto panel = std::make_shared<Panel>(500, 100, 300, 200);
  panel->setColor(50, 50, 50, 255); // dark background

  auto label = std::make_shared<Label>(50, 50, 200, 50, "I am above!");
  auto label2 = std::make_shared<Label>(50, 100, 200, 50, "I am below!");

  auto labelPanel = std::make_shared<Label>(10, 10, 200, 30, "Inside Panel");

  auto button = std::make_shared<Button>(50, 150, 200, 50, "Click me!");

  button->onClick([label, button]() {
    std::cout << "Button clicked!\n";
    label->setText("hello.");
    button->setText("You clicked me.");
    label->setColor(255, 255, 0, 255);
  });

  window.addWidget(label);
  window.addWidget(label2);

  panel->addChild(labelPanel);

  window.addWidget(button);

  window.addWidget(panel);

  label->setColor(0, 255, 0, 255);

  while (window.processEvents()) {
    window.clear(255, 0, 0, 255); // blue background

    window.update();
  }

  return 0;
}