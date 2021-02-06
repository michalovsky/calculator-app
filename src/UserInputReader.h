#pragma once

#include <SFML/Graphics.hpp>
#include <optional>

#include "InputKey.h"

namespace calculator
{
class UserInputReader
{
public:
    UserInputReader(sf::RenderWindow&);

    std::optional<InputKey> readInputKey() const;
    sf::Vector2f readMousePosition() const;

private:
    sf::RenderWindow& window;
};
}
