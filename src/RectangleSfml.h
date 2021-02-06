#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace calculator
{
class RectangleSfml
{
public:
    RectangleSfml(const sf::Vector2f& position, const sf::Vector2f& size, float outlineThickness);

    void updatePosition(const sf::Vector2f& position);
    void changeColor(sf::Color);
    bool isIntersecting(const sf::Vector2f& position) const;
    void draw(sf::RenderWindow&);

private:
    sf::RectangleShape rect;
};
}