#include "RectangleSfml.h"

#include <iostream>

namespace calculator
{

RectangleSfml::RectangleSfml(const sf::Vector2f& position, const sf::Vector2f& size, float outlineThickness)
{
    rect.setSize(size);
    rect.setFillColor(sf::Color::White);
    rect.setOutlineThickness(outlineThickness);
    rect.setOutlineColor(sf::Color::Black);
    rect.setPosition(position);
}

void RectangleSfml::changeColor(sf::Color color)
{
    rect.setFillColor(color);
}

bool RectangleSfml::isIntersecting(const sf::Vector2f& position) const
{
    const sf::Vector2f rectPosition = rect.getPosition();
    const float width = rect.getSize().x;
    const float height = rect.getSize().y;

    return (position.x >= rectPosition.x && position.x <= rectPosition.x + width &&
            position.y >= rectPosition.y && position.y <= rectPosition.y + height);
}

void RectangleSfml::draw(sf::RenderWindow& window)
{
    window.draw(rect);
}
}