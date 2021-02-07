#include "FontStorage.h"

#include <iostream>

#include "FontLoader.h"
#include "exceptions/CannotAccessFontFile.h"
#include "exceptions/FontNotAvailable.h"

namespace calculator
{

std::unordered_map<std::string, std::unique_ptr<sf::Font>> FontStorage::fonts = {};

const sf::Font& FontStorage::getFont(const std::string& path)
{
    if (not fontInStorage(path))
    {
        loadFont(path);
    }
    return *fonts.at(path);
}

void FontStorage::loadFont(const std::string& path)
{
    auto font = std::make_unique<sf::Font>();
    try
    {
        FontLoader::load(*font, path);
    }
    catch (const exceptions::CannotAccessFontFile& e)
    {
        std::cerr << e.what() << std::endl;
        throw exceptions::FontNotAvailable{e.what()};
    }
    fonts[path] = std::move(font);
}

bool FontStorage::fontInStorage(const std::string& path)
{
    return fonts.count(path) == 1;
}

}