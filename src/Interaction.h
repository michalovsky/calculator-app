#pragma once
#include "TilesLayout.h"
#include "Buffer.h"
#include "OperationSolver.h"

class Interaction
{
public:
	Interaction() = delete;
	static void mouseOver(TilesLayout& tilesLayout, sf::Vector2f mousePosition);
	static void mouseClick(TilesLayout& tilesLayout, sf::Vector2f mousePosition, int actionKey);
private:
	static bool isIntersecting(calculator::Tile & tile, sf::Vector2f positionToCheck );
	static void handleNumbers(std::string value);
	static void handleSigns(std::string value);
	static void handleResult();
	static void handleDot(std::string value);
	static void handleClear();
	static void handleRemove();

};

