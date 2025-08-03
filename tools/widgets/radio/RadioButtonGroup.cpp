#include "RadioButtonGroup.h"
#include "RadioButton.h"

void RadioButtonGroup::addButton(RadioButton* button) {
    buttons.push_back(button);
    button->setGroup(this);
}

void RadioButtonGroup::setSelected(RadioButton* selectedButton) {
    for (auto btn : buttons) {
        btn->setSelected(btn == selectedButton);
    }
}

RadioButton* RadioButtonGroup::getSelected() const {
    for (auto btn : buttons) {
        if (btn->isSelected()) return btn;
    }
    return nullptr;
}
