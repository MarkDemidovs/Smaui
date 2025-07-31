#include "./tools/Window.h"
#include "./tools/style/Style.h"
#include "./tools/widgets/label/Label.h"
#include "./tools/widgets/textbox/Textbox.h"
#include "./tools/widgets/button/Button.h"
#include <memory>

int main() {
  Window window("Textbox Example", 800, 600);
  //window.setBackground("tools/creative/ui/wii_home_bg.png");

  Style *buttonStyle =
      loadStyle(window.getRenderer(), "tools/creative/ui/button");

  auto startBtn =
      std::make_shared<Button>(100, 100, 200, 60, "Start");
  window.addWidget(startBtn);

  while (window.processEvents()) {
    window.clear(220, 220, 255, 255); // light blue
    window.update();
  }

  return 0;
}
