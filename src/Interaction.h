#pragma once
#include "Tile.h"
#include "Buffer.h"
#include "OperationSolver.h"

using vectorOfTiles = std::vector<std::unique_ptr<Tile>>;

class Interaction
{
public:
	Interaction() = delete;
	static void mouseOver(vectorOfTiles & tiles, sf::Vector2f mousePosition);
	static void mouseClick(vectorOfTiles & tiles, sf::Vector2f mousePosition, int actionKey);
private:
	static bool isIntersecting(Tile & tile, sf::Vector2f positionToCheck );
	static void handleNumbers(std::string value);
	static void handleSigns(std::string value);
	static void handleResult();
	static void handleDot(std::string value);
	static void handleClear();
	static void handleRemove();

};

