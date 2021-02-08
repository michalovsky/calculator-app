#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "LayoutCharacter.h"
#include "RectangleSfml.h"
#include "TextSfml.h"

namespace calculator
{
class Tile
{
public:
    Tile(const sf::Vector2f& position, const sf::Vector2f& size, float outlineThickness, std::string label,
         unsigned int characterSize, const sf::Vector2f& textOffsetInit,
         std::optional<LayoutCharacter> layoutCharacter);

    void updateLabel(const std::string& updatedLabel);
    void changeColor(sf::Color);
    std::string getText() const;
    std::optional<LayoutCharacter> getLayoutCharacter() const;
    bool isIntersecting(const sf::Vector2f& position) const;
    void draw(sf::RenderWindow&);

private:
    TextSfml text;
    RectangleSfml rectangle;
    const sf::Vector2f textOffset;
    const std::optional<LayoutCharacter> layoutCharacter;
};
}
