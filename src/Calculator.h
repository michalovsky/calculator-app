#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "Buffer.h"
#include "Interaction.h"
#include "TilesLayout.h"
#include "UserInputReader.h"

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
    std::unique_ptr<calculator::Interaction> interaction;
};

