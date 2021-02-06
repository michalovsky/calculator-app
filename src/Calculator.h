#pragma once
#include <iostream>
#include <memory>
#include <vector>

#include "Buffer.h"
#include "Interaction.h"
#include "Tiles.h"
#include "UserInputReader.h"

class Calculator
{
public:
	Calculator();
	~Calculator();
	void run();
private:
	void initialize();
	void clearWindow();
	void update(calculator::InputKey);
	void closeWindow(calculator::InputKey);
	void drawWindow();
	sf::RenderWindow * window;
	std::unique_ptr<Tiles> tiles;
    std::unique_ptr<calculator::UserInputReader> userInputReader;

};

