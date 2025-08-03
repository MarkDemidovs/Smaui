// Including all of the elements that are going to be used.
#include "./tools/Window.h"
#include "./tools/style/Style.h"
#include "./tools/widgets/button/Button.h"
#include "./tools/widgets/label/Label.h"
#include <iostream>
#include <string>

int main() {
  int counter = 0;
  // Creating a window
  Window window("Example Project", 400, 600);

  // Loading a style sheet (premade)
  Style *buttonStyle =
      loadStyle(window.getRenderer(), "tools/creative/ui/button");

  // Creating a label
  auto label = std::make_shared<Label>(180, 150, 50, 50, "0");
  // Setting the labels colour
  label->setColor(0, 0, 0, 255);

  // Creating the buttons
  auto incBtn =
      std::make_shared<Button>(100, 300, 200, 60, "Increment", buttonStyle);
  auto decBtn =
      std::make_shared<Button>(100, 400, 200, 60, "Decrement", buttonStyle);

  // Button click functionality [here must be all elements that are going to be
  // used in the function
  incBtn->onClick([label, incBtn, &counter]() {
    counter++;
    label->setText(std::to_string(counter));
  });

  decBtn->onClick([label, decBtn, &counter]() {
    counter--;
    label->setText(std::to_string(counter));
  });

  // Adding widgets to our window
  window.addWidget(label);
  window.addWidget(incBtn);
  window.addWidget(decBtn);

  // Main loop (necessary, used for detecting everything new that happens)
  while (window.processEvents()) {
    window.clear(220, 220, 220, 255);
    window.update();
  }

  return 0;
}
