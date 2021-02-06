#pragma once

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace calculator
{
class TextSfml
{
public:
    TextSfml(const sf::Vector2f& positionInit, std::string valueInit, unsigned int characterSizeInit);

    void update(const sf::Vector2f& position);
    void update(const sf::Vector2f& position, const std::string& updatedValue);
    std::string getValue() const;
    void draw(sf::RenderWindow&);

private:
    std::string value;
    sf::Text text;
    sf::Font font;
};
}