#include "./tools/Window.h"
#include "./tools/widgets/radio/RadioButton.h"
#include "./tools/widgets/radio/RadioButtonGroup.h"
#include <memory>

int main() {
    Window window("Radio Button Demo", 600, 400);

    RadioButtonGroup group;

    auto rb1 = std::make_shared<RadioButton>(50, 50, 20, "Option 1");
    auto rb2 = std::make_shared<RadioButton>(50, 80, 20, "Option 2");
    auto rb3 = std::make_shared<RadioButton>(50, 110, 20, "Option 3");

    group.addButton(rb1.get());
    group.addButton(rb2.get());
    group.addButton(rb3.get());

    window.addWidget(rb1);
    window.addWidget(rb2);
    window.addWidget(rb3);

    while (window.processEvents()) {
        window.clear(255, 255, 255, 255);
        window.update();
    }

    return 0;
}
