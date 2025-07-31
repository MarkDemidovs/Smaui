#include "./tools/Window.h"
#include "./tools/widgets/label/Label.h"
#include "./tools/widgets/textbox/Textbox.h"
#include <memory>

int main() {
  Window window("Textbox Example", 800, 600);

  auto label = std::make_shared<Label>(50, 50, 200, 50, "Type Below:");
  auto textbox = std::make_shared<TextBox>(50, 120, 300, 40);

  window.addWidget(label);
  window.addWidget(textbox);

  while (window.processEvents()) {
    window.clear(220, 220, 255, 255); // light blue
    window.update();
  }

  return 0;
}
