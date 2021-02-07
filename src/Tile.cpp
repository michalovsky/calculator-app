#include "Tile.h"

#include <iostream>
#include <utility>

namespace calculator
{

Tile::Tile(const sf::Vector2f& position, const sf::Vector2f& size, float outlineThickness, std::string label,
           unsigned int characterSize, const sf::Vector2f& textOffsetInit,
           std::optional<LayoutCharacter> layoutCharacterInit)
    : text{position + textOffsetInit, std::move(label), characterSize},
      rectangle{position, size, outlineThickness},
      textOffset{textOffsetInit},
      layoutCharacter{layoutCharacterInit}
{
}

void Tile::update(const sf::Vector2f& updatedPosition)
{
    rectangle.updatePosition(updatedPosition);
    text.update(updatedPosition + textOffset);
}

void Tile::update(const sf::Vector2f& updatedPosition, const std::string& updatedLabel)
{
    rectangle.updatePosition(updatedPosition);
    text.update(updatedPosition + textOffset, updatedLabel);
}

void Tile::changeColor(sf::Color color)
{
    rectangle.changeColor(color);
}

std::string Tile::getText() const
{
    return text.getValue();
}

std::optional<LayoutCharacter> Tile::getLayoutCharacter() const
{
    return layoutCharacter;
}

bool Tile::isIntersecting(const sf::Vector2f& position) const
{
    return rectangle.isIntersecting(position);
}

void Tile::draw(sf::RenderWindow& window)
{
    rectangle.draw(window);
    text.draw(window);
}

}
