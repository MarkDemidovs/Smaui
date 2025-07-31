#ifndef PANEL_H
#define PANEL_H

#include "../../Widget.h"
#include <vector>
#include <memory>

class Panel : public Widget {
public:
    Panel(int x, int y, int w, int h);

    void draw(SDL_Renderer* renderer) override;
    void handleEvent(const SDL_Event& e) override;
    void addChild(std::shared_ptr<Widget> widget);
    void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

private:
    std::vector<std::shared_ptr<Widget>> children;
    SDL_Color bgColor = { 0, 0, 0, 0 }; // transparent by default
};

#endif
