#include "Tiles.h"

#include "LayoutCharacter.h"
#include "TileCreator.h"

using namespace calculator;

Tiles::Tiles() : tilePositions{createTilePositions()}, tiles{createTiles()} {}

void Tiles::update(const std::string& resultLine)
{
    for (int tileIndex = 0; tileIndex <= tiles.size(); tileIndex++)
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

const std::array<std::unique_ptr<calculator::Tile>, 19>& Tiles::getTiles()
{
    return tiles;
}

void Tiles::draw(sf::RenderWindow& window)
{
    for (const auto& tile : tiles)
    {
        tile->draw(window);
    }
}

std::array<sf::Vector2f, 19>& Tiles::createTilePositions()
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

std::array<std::unique_ptr<calculator::Tile>, 19>& Tiles::createTiles()
{
    const auto tilePositions = createTilePositions();

    static std::array<std::unique_ptr<calculator::Tile>, 19> tilesInit = {
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Number0)],
                                                   toString(LayoutCharacter::Number0)),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Number1)],
                                                   toString(LayoutCharacter::Number0)),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Number2)],
                                                   toString(LayoutCharacter::Number0)),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Number3)],
                                                   toString(LayoutCharacter::Number0)),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Number4)],
                                                   toString(LayoutCharacter::Number0)),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Number5)],
                                                   toString(LayoutCharacter::Number0)),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Number6)],
                                                   toString(LayoutCharacter::Number0)),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Number7)],
                                                   toString(LayoutCharacter::Number0)),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Number8)],
                                                   toString(LayoutCharacter::Number0)),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Number9)],
                                                   toString(LayoutCharacter::Number0)),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Plus)],
                                                   toString(LayoutCharacter::Number0)),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Minus)],
                                                   toString(LayoutCharacter::Number0)),
        calculator::TileCreator::createRegularTile(
            tilePositions[static_cast<int>(LayoutCharacter::Multiplication)],
            toString(LayoutCharacter::Number0)),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Division)],
                                                   toString(LayoutCharacter::Number0)),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Equal)],
                                                   toString(LayoutCharacter::Number0)),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Remove)],
                                                   toString(LayoutCharacter::Number0)),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Clear)],
                                                   toString(LayoutCharacter::Number0)),
        calculator::TileCreator::createRegularTile(tilePositions[static_cast<int>(LayoutCharacter::Dot)],
                                                   toString(LayoutCharacter::Number0)),
        calculator::TileCreator::createResultTile(tilePositions[resultTileIndex])};

    return tilesInit;
}
