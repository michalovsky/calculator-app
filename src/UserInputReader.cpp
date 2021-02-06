#include "UserInputReader.h"

namespace calculator
{

UserInputReader::UserInputReader(sf::RenderWindow& windowInit) : window{windowInit} {}

std::optional<InputKey> UserInputReader::readInputKey() const
{
    sf::Event event{};
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
        {
            return InputKey::MouseLeft;
        }
        else if ((event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) ||
                 event.type == sf::Event::Closed)
        {
            return InputKey::Escape;
        }
    }

    return std::nullopt;
}

sf::Vector2f UserInputReader::readMousePosition() const
{
    return sf::Vector2f(sf::Mouse::getPosition(window));
}
}
