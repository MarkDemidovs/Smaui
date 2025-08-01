#include "./tools/Window.h"
#include "./tools/widgets/label/Label.h"
#include "./tools/widgets/checkbox/Checkbox.h"
#include <memory>

int main() {
    Window window("Checkbox Demo", 600, 400);

    auto checkbox1 = std::make_shared<Checkbox>(50, 50, 20, "Enable feature");
    auto checkbox2 = std::make_shared<Checkbox>(50, 100, 20, "Show advanced options");

    window.addWidget(checkbox1);
    window.addWidget(checkbox2);

    while (window.processEvents()) {
        window.clear(255, 255, 255, 255);
        window.update();
    }

    return 0;
}
