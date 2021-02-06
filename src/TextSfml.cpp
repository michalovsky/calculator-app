#include "TextSfml.h"

#include <utility>

#include "FontLoader.h"
#include "GetProjectPath.h"

namespace calculator
{
namespace
{
const std::string fontName = "arial.ttf";
}

TextSfml::TextSfml(const sf::Vector2f& positionInit, std::string valueInit, unsigned int characterSizeInit) : value{std::move(valueInit)}
{
    const auto resourcesDirectory = utils::getProjectPath("calculator-app") + "resources/";
    const auto fontFilePath = resourcesDirectory + fontName;
    FontLoader::load(font, fontFilePath);

    text.setFont(font);
    text.setCharacterSize(characterSizeInit);
    text.setFillColor(sf::Color::Black);
    text.setString(value);
    text.setPosition(positionInit);
}

void TextSfml::update(const sf::Vector2f& position)
{
    text.setPosition(position);
}

void TextSfml::update(const sf::Vector2f& position, const std::string& updatedValue)
{
    text.setPosition(position);
    text.setString(updatedValue);
}

std::string TextSfml::getValue() const
{
    return value;
}

void TextSfml::draw(sf::RenderWindow& window)
{
    window.draw(text);
}

}