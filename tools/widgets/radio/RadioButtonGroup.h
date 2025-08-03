#pragma once
#include <vector>
#include <memory>

class RadioButton;

class RadioButtonGroup {
private:
    std::vector<RadioButton*> buttons;

public:
    void addButton(RadioButton* button);
    void setSelected(RadioButton* selectedButton);
    RadioButton* getSelected() const;
};
