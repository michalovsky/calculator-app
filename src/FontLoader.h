#pragma once

#include "SFML/Graphics/Font.hpp"

namespace calculator
{
class FontLoader
{
public:
    static void load(sf::Font&, const std::string& fontPath);
};
}