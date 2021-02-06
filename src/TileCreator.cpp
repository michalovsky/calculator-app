#include "TileCreator.h"

namespace calculator
{

std::unique_ptr<Tile> TileCreator::createRegularTile(const sf::Vector2f& position, const std::string& label,
                                                     std::optional<LayoutCharacter> layoutCharacter)
{
    const auto size = sf::Vector2f(70.f, 60.f);
    const auto outlineThickness = 1.f;
    const auto characterSize = 40u;
    const auto textOffset = sf::Vector2f(28.f, 5.f);

    return std::make_unique<Tile>(position, size, outlineThickness, label, characterSize, textOffset,
                                  layoutCharacter);
}

std::unique_ptr<Tile> TileCreator::createResultTile(const sf::Vector2f& position)
{
    const auto size = sf::Vector2f(294.f, 60.f);
    const auto outlineThickness = 3.f;
    const auto characterSize = 50u;
    const auto textOffset = sf::Vector2f(5.f, 0.f);

    return std::make_unique<Tile>(position, size, outlineThickness, "0", characterSize, textOffset,
                                  std::nullopt);
}
}