#pragma once
#include "Tiles.h"
#include "Buffer.h"
#include "Interaction.h"
#include "Input.h"
#include <memory>
#include <vector>
#include <iostream>

class Calculator
{
public:
	Calculator();
	~Calculator();
	void run();
private:
	void initialize();
	void clearWindow();
	void update(int inputKey);
	void closeWindow(int inputKey);
	void drawWindow();
	sf::RenderWindow * window;
	std::unique_ptr<Tiles> tiles;

};

