#include "UserInputReader.h"

#include <SFML/Window/Event.hpp>

namespace calculator
{

UserInputReader::UserInputReader(std::shared_ptr<sf::RenderWindow> windowInit) : window{std::move(windowInit)}
{
}

std::optional<InputKey> UserInputReader::readInputKey() const
{
    sf::Event event{};
    while (window->pollEvent(event))
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
    return sf::Vector2f(sf::Mouse::getPosition(*window));
}
}
