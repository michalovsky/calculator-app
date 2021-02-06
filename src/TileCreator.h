#pragma once

#include "Tile.h"

namespace calculator
{
class TileCreator
{
public:
    static std::unique_ptr<Tile> createRegularTile(const sf::Vector2f& position, const std::string& label,
                                                   std::optional<LayoutCharacter> layoutCharacter);
    static std::unique_ptr<Tile> createResultTile(const sf::Vector2f& position);
};
}