#include "Calculator.h"



Calculator::Calculator()
{
    window = new sf::RenderWindow(sf::VideoMode(300, 480), "Calculator");
    window->setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - window->getSize().x / 2, sf::VideoMode::getDesktopMode().height / 2 - window->getSize().y / 2));
    window->setFramerateLimit(60);
	tiles = std::make_unique<TilesLayout>();

    userInputReader = std::make_unique<calculator::UserInputReader>(*window);
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
		auto input = userInputReader->readInputKey();
        if (input)
        {
            closeWindow(*input);
            update(*input);
        }

		drawWindow();
	}
}

void Calculator::initialize()
{

}


void Calculator::update(calculator::InputKey inputKey)
{
	Interaction::mouseOver(*tiles, userInputReader->readMousePosition());
	Interaction::mouseClick(*tiles, userInputReader->readMousePosition(), (int)inputKey);
	tiles->updateResult(Buffer::getWordsAsLine());
}

void Calculator::clearWindow()
{
	window->clear(sf::Color::White);
}

void Calculator::closeWindow(calculator::InputKey inputKey)
{
	if (inputKey == calculator::InputKey::Escape)
	{
		window->close();
	}
}

void Calculator::drawWindow()
{
    tiles->draw(*window);
	window->display();
}
