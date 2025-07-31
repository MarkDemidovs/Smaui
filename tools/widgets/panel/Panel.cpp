#include "./Panel.h"

Panel::Panel(int x, int y, int w, int h) : Widget(x, y, w, h) {}

void Panel::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    bgColor = { r, g, b, a };
}

void Panel::addChild(std::shared_ptr<Widget> widget) {
    // Position of child is *relative* to panel
    children.push_back(widget);
}

void Panel::draw(SDL_Renderer* renderer) {
    // Draw background if not transparent
    if (bgColor.a > 0) {
        SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
        SDL_Rect rect = { x, y, width, height };
        SDL_RenderFillRect(renderer, &rect);
    }

    // Draw children relative to panel
    for (auto& child : children) {
        // Offset the rendering context
        child->moveTo(x + child->getX(), y + child->getY());
        child->draw(renderer);
        child->moveTo(child->getX() - x, child->getY() - y); // restore
    }
}

void Panel::handleEvent(const SDL_Event& e) {
    SDL_Event localEvent = e;

    if (e.type == SDL_MOUSEMOTION) {
        localEvent.motion.x -= x;
        localEvent.motion.y -= y;
    } else if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP) {
        localEvent.button.x -= x;
        localEvent.button.y -= y;
    }

    for (auto& child : children) {
        child->handleEvent(localEvent);
    }
}
