#include "Tiles.h"


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

	tiles.push_back(std::unique_ptr<Tile>(new Tile("+", tilesPositions[(int)Characters::PLUS])));
	tiles.push_back(std::unique_ptr<Tile>(new Tile("-", tilesPositions[(int)Characters::MINUS])));
	tiles.push_back(std::unique_ptr<Tile>(new Tile("x", tilesPositions[(int)Characters::MULTIPLICATION])));
	tiles.push_back(std::unique_ptr<Tile>(new Tile("/", tilesPositions[(int)Characters::DIVISION])));
	tiles.push_back(std::unique_ptr<Tile>(new Tile("=", tilesPositions[(int)Characters::EQUALS])));
	tiles.push_back(std::unique_ptr<Tile>(new Tile("<-", tilesPositions[(int)Characters::REMOVE])));
	tiles.push_back(std::unique_ptr<Tile>(new Tile("C", tilesPositions[(int)Characters::CLEAR])));
	tiles.push_back(std::unique_ptr<Tile>(new Tile(".", tilesPositions[(int)Characters::DOT])));
	tiles.push_back(std::unique_ptr<Tile>(new Tile(tilesPositions[(int)Characters::RESULT])));
}

void Tiles::initializePositions()
{
	for (int counter = 0; counter <= amountOfTiles; counter++)
	{
		tilesPositions.push_back({ 0,0 });
	}

	tilesPositions[(int)Characters::ZERO] = sf::Vector2f(145, 500);
	tilesPositions[(int)Characters::ONE] = sf::Vector2f(70, 435);
	tilesPositions[(int)Characters::TWO] = sf::Vector2f(145, 435);
	tilesPositions[(int)Characters::THREE] = sf::Vector2f(220, 435);
	tilesPositions[(int)Characters::FOUR] = sf::Vector2f(70, 370);
	tilesPositions[(int)Characters::FIVE] = sf::Vector2f(145, 370);
	tilesPositions[(int)Characters::SIX] = sf::Vector2f(220, 370);
	tilesPositions[(int)Characters::SEVEN] = sf::Vector2f(70, 305);
	tilesPositions[(int)Characters::EIGHT] = sf::Vector2f(145, 305);
	tilesPositions[(int)Characters::NINE] = sf::Vector2f(220, 305);
	tilesPositions[(int)Characters::PLUS] = sf::Vector2f(295, 435);
	tilesPositions[(int)Characters::MINUS] = sf::Vector2f(295, 370);
	tilesPositions[(int)Characters::MULTIPLICATION] = sf::Vector2f(295, 305);
	tilesPositions[(int)Characters::DIVISION] = sf::Vector2f(295, 240);
	tilesPositions[(int)Characters::EQUALS] = sf::Vector2f(295, 500);
	tilesPositions[(int)Characters::REMOVE] = sf::Vector2f(220, 240);
	tilesPositions[(int)Characters::CLEAR] = sf::Vector2f(145, 240);
	tilesPositions[(int)Characters::DOT] = sf::Vector2f(220, 500);
	tilesPositions[(int)Characters::RESULT] = sf::Vector2f(3 + 67, 20 + 83);

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
		if (tileIndex == (int)Characters::RESULT)
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

