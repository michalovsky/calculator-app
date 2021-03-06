#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <optional>

#include "InputKey.h"

namespace calculator
{
class UserInputReader
{
public:
    UserInputReader(std::shared_ptr<sf::RenderWindow>);

    std::optional<InputKey> readInputKey() const;
    sf::Vector2f readMousePosition() const;

private:
    std::shared_ptr<sf::RenderWindow> window;
};
}
