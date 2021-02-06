#include "Tiles.h"

#include "LayoutCharacter.h"

using namespace calculator;

Tiles::Tiles()
{
	initialize();
}

void Tiles::initialize()
{
	initializePositions();

	for (int tileIndex = 0; tileIndex <= 9; tileIndex++)
	{
		tiles.push_back(std::unique_ptr<Tile>(new Tile(std::to_string(tileIndex), tilesPositions[tileIndex])));
	}

	tiles.push_back(std::unique_ptr<Tile>(new Tile("+", tilesPositions[(int)LayoutCharacter::Plus])));
	tiles.push_back(std::unique_ptr<Tile>(new Tile("-", tilesPositions[(int)LayoutCharacter::Minus])));
	tiles.push_back(std::unique_ptr<Tile>(new Tile("x", tilesPositions[(int)LayoutCharacter::Multiplication])));
	tiles.push_back(std::unique_ptr<Tile>(new Tile("/", tilesPositions[(int)LayoutCharacter::Division])));
	tiles.push_back(std::unique_ptr<Tile>(new Tile("=", tilesPositions[(int)LayoutCharacter::Equal])));
	tiles.push_back(std::unique_ptr<Tile>(new Tile("<-", tilesPositions[(int)LayoutCharacter::Remove])));
	tiles.push_back(std::unique_ptr<Tile>(new Tile("C", tilesPositions[(int)LayoutCharacter::Clear])));
	tiles.push_back(std::unique_ptr<Tile>(new Tile(".", tilesPositions[(int)LayoutCharacter::Dot])));
	tiles.push_back(std::unique_ptr<Tile>(new Tile(tilesPositions[(int)LayoutCharacter::Result])));
}

void Tiles::initializePositions()
{
	for (int counter = 0; counter <= amountOfTiles; counter++)
	{
		tilesPositions.push_back({ 0,0 });
	}

	tilesPositions[(int)LayoutCharacter::Number0] = sf::Vector2f(145, 500);
	tilesPositions[(int)LayoutCharacter::Number1] = sf::Vector2f(70, 435);
	tilesPositions[(int)LayoutCharacter::Number2] = sf::Vector2f(145, 435);
	tilesPositions[(int)LayoutCharacter::Number3] = sf::Vector2f(220, 435);
	tilesPositions[(int)LayoutCharacter::Number4] = sf::Vector2f(70, 370);
	tilesPositions[(int)LayoutCharacter::Number5] = sf::Vector2f(145, 370);
	tilesPositions[(int)LayoutCharacter::Number6] = sf::Vector2f(220, 370);
	tilesPositions[(int)LayoutCharacter::Number7] = sf::Vector2f(70, 305);
	tilesPositions[(int)LayoutCharacter::Number8] = sf::Vector2f(145, 305);
	tilesPositions[(int)LayoutCharacter::Number9] = sf::Vector2f(220, 305);
	tilesPositions[(int)LayoutCharacter::Plus] = sf::Vector2f(295, 435);
	tilesPositions[(int)LayoutCharacter::Minus] = sf::Vector2f(295, 370);
	tilesPositions[(int)LayoutCharacter::Multiplication] = sf::Vector2f(295, 305);
	tilesPositions[(int)LayoutCharacter::Division] = sf::Vector2f(295, 240);
	tilesPositions[(int)LayoutCharacter::Equal] = sf::Vector2f(295, 500);
	tilesPositions[(int)LayoutCharacter::Remove] = sf::Vector2f(220, 240);
	tilesPositions[(int)LayoutCharacter::Clear] = sf::Vector2f(145, 240);
	tilesPositions[(int)LayoutCharacter::Dot] = sf::Vector2f(220, 500);
	tilesPositions[(int)LayoutCharacter::Result] = sf::Vector2f(3 + 67, 20 + 83);

	for (auto & position : tilesPositions)
	{
		position.x -= 67;
		position.y -= 83;
	}
}

void Tiles::update(std::string resultLine)
{
	int tileIndex = 0;
	for (std::unique_ptr<Tile> & tile : tiles)
	{
		if (tileIndex == (int)LayoutCharacter::Result)
		{
			tile->updateResultTile(tilesPositions[tileIndex], resultLine);
		}
		else
		{
			tile->updateRegularTile(tilesPositions[tileIndex]);
		}

		tileIndex++;
	}
}

std::vector<std::unique_ptr<Tile>> & Tiles::getTiles()
{
	return tiles;
}

