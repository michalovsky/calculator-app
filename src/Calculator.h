#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "Buffer.h"
#include "InteractionHandler.h"
#include "TilesLayout.h"
#include "UserInputReader.h"
#include "IntersectedTileInformationInterpreter.h"

class Calculator
{
public:
	Calculator();
	~Calculator();

	void run();
private:
	void clearWindow();
	void update();
	void closeWindow();
	void drawWindow();

	sf::RenderWindow * window;
	std::unique_ptr<TilesLayout> tiles;
    std::unique_ptr<calculator::UserInputReader> userInputReader;
    std::shared_ptr<calculator::Buffer> buffer;
    std::unique_ptr<calculator::InteractionHandler> interactionHandler;
    std::unique_ptr<calculator::IntersectedTileInformationInterpreter> tileInformationInterpreter;
};

