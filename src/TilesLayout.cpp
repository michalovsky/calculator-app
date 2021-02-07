#include "TilesLayout.h"

#include "LayoutCharacter.h"
#include "TileCreator.h"

namespace calculator
{
namespace
{
const auto number0Position = sf::Vector2f{78, 417};
const auto number1Position = sf::Vector2f{3, 352};
const auto number2Position = sf::Vector2f{78, 352};
const auto number3Position = sf::Vector2f{153, 352};
const auto number4Position = sf::Vector2f{3, 287};
const auto number5Position = sf::Vector2f{78, 287};
const auto number6Position = sf::Vector2f{153, 287};
const auto number7Position = sf::Vector2f{3, 222};
const auto number8Position = sf::Vector2f{78, 222};
const auto number9Position = sf::Vector2f{153, 222};
const auto plusPosition = sf::Vector2f{228, 352};
const auto minusPosition = sf::Vector2f{228, 287};
const auto multiplicationPosition = sf::Vector2f{228, 222};
const auto divisionPosition = sf::Vector2f{228, 157};
const auto equalPosition = sf::Vector2f{228, 417};
const auto removePosition = sf::Vector2f{153, 157};
const auto clearPosition = sf::Vector2f{78, 157};
const auto dotPosition = sf::Vector2f{153, 417};
const auto resultPosition = sf::Vector2f{3, 50};
}

TilesLayout::TilesLayout() : tilePositions{createTilePositions()}, tiles{createTiles()} {}

void TilesLayout::updateResult(const std::string& resultLine)
{
    tiles[resultTileIndex]->updateLabel(resultLine);
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
        number0Position,        number1Position,  number2Position, number3Position,
        number4Position,        number5Position,  number6Position, number7Position,
        number8Position,        number9Position,  plusPosition,    minusPosition,
        multiplicationPosition, divisionPosition, equalPosition,   removePosition,
        clearPosition,          dotPosition,      resultPosition};
    return tilePositions;
}

std::array<std::unique_ptr<Tile>, 19>& TilesLayout::createTiles()
{
    const auto& tilePositions = createTilePositions();
    static std::array<std::unique_ptr<Tile>, 19> tilesInit = {
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
        TileCreator::createResultTile(tilePositions[resultTileIndex])};
    return tilesInit;
}

std::unique_ptr<Tile> TilesLayout::createRegularTile(LayoutCharacter layoutCharacter)
{
    const auto& tilePositions = createTilePositions();
    return TileCreator::createRegularTile(tilePositions[static_cast<int>(layoutCharacter)],
                                          toString(layoutCharacter), layoutCharacter);
}
}