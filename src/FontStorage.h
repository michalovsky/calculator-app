#pragma once

#include <unordered_map>
#include <string>

namespace calculator
{
class FontStorage
{
public:
    static const sf::Font& getFont(const std::string& path);

private:
    static void loadFont(const std::string& path);
    static bool fontInStorage(const std::string& path);

    static std::unordered_map<std::string, std::unique_ptr<sf::Font>> fonts;
};
}