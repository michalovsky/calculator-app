#include "Calculator.h"



Calculator::Calculator()
{
	tiles = std::unique_ptr<Tiles>(new Tiles());

	initialize();
}


Calculator::~Calculator()
{
	delete window;
}

void Calculator::run()
{
	while (window->isOpen())
	{
		clearWindow();
		int input = Input::read(*window);
		closeWindow(input);
		update(input);
		drawWindow();
	}
}

void Calculator::initialize()
{
	window = new sf::RenderWindow(sf::VideoMode(300, 480), "Calculator");
	window->setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - window->getSize().x / 2, sf::VideoMode::getDesktopMode().height / 2 - window->getSize().y / 2));
	window->setFramerateLimit(60);
}


void Calculator::update(int inputKey)
{
	Interaction::mouseOver(tiles->getTiles(), Input::readMousePosition(*window));
	Interaction::mouseClick(tiles->getTiles(), Input::readMousePosition(*window), inputKey);
	tiles->update(Buffer::getWordsAsLine());
}

void Calculator::clearWindow()
{
	window->clear(sf::Color::White);
}

void Calculator::closeWindow(int inputKey)
{
	if (inputKey == (int)Inputs::ESCAPE)
	{
		window->close();
	}
}

void Calculator::drawWindow()
{
	int index = 0;
	for (std::unique_ptr<Tile> & tile : tiles->getTiles())
	{
		window->draw(tile->getRect());
		window->draw(tile->getText());
		index++;
	}

	window->display();
}
