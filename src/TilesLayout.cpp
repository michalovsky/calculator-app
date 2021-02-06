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
        position.x -= 67;
        position.y -= 83;
    }

    return tilePositions;
}

std::array<std::unique_ptr<calculator::Tile>, 19>& TilesLayout::createTiles()
{
    const auto tilePositions = createTilePositions();

    // TODO: function for call createTile with enum
    static std::array<std::unique_ptr<calculator::Tile>, 19> tilesInit = {
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Number0)],
                                                   toString(LayoutCharacter::Number0),
                                                   LayoutCharacter::Number0),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Number1)],
                                                   toString(LayoutCharacter::Number1),
                                                   LayoutCharacter::Number1),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Number2)],
                                                   toString(LayoutCharacter::Number2),
                                                   LayoutCharacter::Number2),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Number3)],
                                                   toString(LayoutCharacter::Number3),
                                                   LayoutCharacter::Number3),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Number4)],
                                                   toString(LayoutCharacter::Number4),
                                                   LayoutCharacter::Number4),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Number5)],
                                                   toString(LayoutCharacter::Number5),
                                                   LayoutCharacter::Number5),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Number6)],
                                                   toString(LayoutCharacter::Number6),
                                                   LayoutCharacter::Number6),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Number7)],
                                                   toString(LayoutCharacter::Number7),
                                                   LayoutCharacter::Number7),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Number8)],
                                                   toString(LayoutCharacter::Number8),
                                                   LayoutCharacter::Number8),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Number9)],
                                                   toString(LayoutCharacter::Number9),
                                                   LayoutCharacter::Number9),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Plus)],
                                                   toString(LayoutCharacter::Plus), LayoutCharacter::Plus),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Minus)],
                                                   toString(LayoutCharacter::Minus), LayoutCharacter::Minus),
        calculator::TileCreator::createRegularTile(
            tilePositions[static_cast<int>(LayoutCharacter::Multiplication)],
            toString(LayoutCharacter::Multiplication), LayoutCharacter::Multiplication),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Division)],
                                                   toString(LayoutCharacter::Division),
                                                   LayoutCharacter::Division),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Equal)],
                                                   toString(LayoutCharacter::Equal), LayoutCharacter::Equal),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Remove)],
                                                   toString(LayoutCharacter::Remove),
                                                   LayoutCharacter::Remove),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Clear)],
                                                   toString(LayoutCharacter::Clear), LayoutCharacter::Clear),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Dot)],
                                                   toString(LayoutCharacter::Dot), LayoutCharacter::Dot),
        calculator::TileCreator::createResultTile(tilePositions[resultTileIndex])};

    return tilesInit;
}
