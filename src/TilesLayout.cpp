#include "TilesLayout.h"

#include <iostream>

#include "LayoutCharacter.h"
#include "TileCreator.h"

using namespace calculator;

TilesLayout::TilesLayout() : tilePositions{createTilePositions()}, tiles{createTiles()} {}

void TilesLayout::update(const std::string& resultLine)
{
    for (int tileIndex = 0; tileIndex < tiles.size(); tileIndex++)
    {
        if (tileIndex == resultTileIndex)
        {
            tiles[tileIndex]->update(tilePositions[tileIndex], resultLine);
        }
        else
        {
            tiles[tileIndex]->update(tilePositions[tileIndex]);
        }
    }
}

void TilesLayout::changeTilesColor(sf::Color color)
{
    for (const auto& tile : tiles)
    {
        tile->changeColor(color);
    }
}

void TilesLayout::changeTilesColorOnIntersection(sf::Color color, const sf::Vector2f& position)
{
    for (int tileIndex = 0; tileIndex < tiles.size(); tileIndex++)
    {
        auto& tile = tiles[tileIndex];
        if (tile->isIntersecting(position) && tileIndex != resultTileIndex)
        {
            tile->changeColor(color);
        }
    }
}

std::optional<IntersectedTileInformation>
TilesLayout::getInformationAboutTileBeingIntersected(const sf::Vector2f& position)
{
    for (int tileIndex = 0; tileIndex < tiles.size(); tileIndex++)
    {
        auto& tile = tiles[tileIndex];
        if (tile->isIntersecting(position) && tileIndex != resultTileIndex)
        {
            if (const auto layoutCharacter = tile->getLayoutCharacter())
            {
                return IntersectedTileInformation{tile->getText(), *layoutCharacter};
            }
        }
    }
    return std::nullopt;
}

void TilesLayout::draw(sf::RenderWindow& window)
{
    for (const auto& tile : tiles)
    {
        tile->draw(window);
    }
}

std::array<sf::Vector2f, 19>& TilesLayout::createTilePositions()
{
    static std::array<sf::Vector2f, 19> tilePositions = {
        sf::Vector2f{145, 500}, sf::Vector2f{70, 435},  sf::Vector2f{145, 435}, sf::Vector2f{220, 435},
        sf::Vector2f{70, 370},  sf::Vector2f{145, 370}, sf::Vector2f{220, 370}, sf::Vector2f(70, 305),
        sf::Vector2f(145, 305), sf::Vector2f(220, 305), sf::Vector2f(295, 435), sf::Vector2f(295, 370),
        sf::Vector2f(295, 305), sf::Vector2f(295, 240), sf::Vector2f(295, 500), sf::Vector2f(220, 240),
        sf::Vector2f(145, 240), sf::Vector2f(220, 500), sf::Vector2f(70, 103)};

    for (auto& position : tilePositions)
    {
        //        position.x -= 67;
        //        position.y -= 83;
    }

    return tilePositions;
}

std::array<std::unique_ptr<calculator::Tile>, 19>& TilesLayout::createTiles()
{
    const auto& tilePositions = createTilePositions();

    static std::array<std::unique_ptr<calculator::Tile>, 19> tilesInit = {
        createRegularTile(LayoutCharacter::Number0),
        createRegularTile(LayoutCharacter::Number1),
        createRegularTile(LayoutCharacter::Number2),
        createRegularTile(LayoutCharacter::Number3),
        createRegularTile(LayoutCharacter::Number4),
        createRegularTile(LayoutCharacter::Number5),
        createRegularTile(LayoutCharacter::Number6),
        createRegularTile(LayoutCharacter::Number7),
        createRegularTile(LayoutCharacter::Number8),
        createRegularTile(LayoutCharacter::Number9),
        createRegularTile(LayoutCharacter::Plus),
        createRegularTile(LayoutCharacter::Minus),
        createRegularTile(LayoutCharacter::Multiplication),
        createRegularTile(LayoutCharacter::Division),
        createRegularTile(LayoutCharacter::Equal),
        createRegularTile(LayoutCharacter::Remove),
        createRegularTile(LayoutCharacter::Clear),
        createRegularTile(LayoutCharacter::Dot),
        calculator::TileCreator::createResultTile(tilePositions[resultTileIndex])};

    return tilesInit;
}

std::unique_ptr<calculator::Tile> TilesLayout::createRegularTile(calculator::LayoutCharacter layoutCharacter)
{
    const auto& tilePositions = createTilePositions();
    return calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(layoutCharacter)],
                                                      toString(layoutCharacter), layoutCharacter);
}
