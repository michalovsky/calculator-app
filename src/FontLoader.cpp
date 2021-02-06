#include "FontLoader.h"

#include "exceptions/CannotAccessFontFile.h"

namespace calculator
{

void FontLoader::load(sf::Font& font, const std::string& fontPath)
{
    if (not font.loadFromFile(fontPath))
    {
        throw exceptions::CannotAccessFontFile("Cannot load font: " + fontPath);
    }
}
}