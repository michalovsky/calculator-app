#pragma once

#include <array>
#include <memory>

#include "IntersectedTileInformation.h"
#include "Tile.h"

namespace calculator
{
class TilesLayout
{
public:
    TilesLayout();

    void updateResult(const std::string& result);
    void changeTilesColor(sf::Color);
    void changeTilesColorOnIntersection(sf::Color, const sf::Vector2f& position);
    std::optional<IntersectedTileInformation>
    getInformationAboutTileBeingIntersected(const sf::Vector2f& position);
    void draw(sf::RenderWindow&);

private:
    static const std::array<sf::Vector2f, 19>& createTilePositions();
    static const std::array<std::unique_ptr<Tile>, 19>& createTiles();
    static std::unique_ptr<Tile> createRegularTile(LayoutCharacter);

    const std::array<sf::Vector2f, 19>& tilePositions;
    const std::array<std::unique_ptr<Tile>, 19>& tiles;
    static const int resultTileIndex = 18;
};
}
