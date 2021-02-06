#pragma once

#include <array>
#include <memory>

#include "Tile.h"
#include "LayoutCharacter.h"

struct IntersectedTileInformation
{
    std::string text;
    calculator::LayoutCharacter layoutCharacter;
};

class TilesLayout
{
public:
    TilesLayout();

    void update(const std::string& resultLine);
    void changeTilesColor(sf::Color);
    void changeTilesColorOnIntersection(sf::Color, const sf::Vector2f& position);
    std::optional<IntersectedTileInformation> getInformationAboutTileBeingIntersected(const sf::Vector2f& position);
    void draw(sf::RenderWindow&);

private:
    static std::array<sf::Vector2f, 19>& createTilePositions();
    static std::array<std::unique_ptr<calculator::Tile>, 19>& createTiles();

    const std::array<sf::Vector2f, 19>& tilePositions;
    const std::array<std::unique_ptr<calculator::Tile>, 19>& tiles;
    static const int resultTileIndex = 18;
};
