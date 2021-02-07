#include "Calculator.h"



Calculator::Calculator()
{
    window = new sf::RenderWindow(sf::VideoMode(300, 480), "Calculator");
    window->setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - window->getSize().x / 2, sf::VideoMode::getDesktopMode().height / 2 - window->getSize().y / 2));
    window->setFramerateLimit(60);
	tiles = std::make_unique<TilesLayout>();
    interaction = std::make_unique<calculator::Interaction>();

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
        update();
		drawWindow();
	}
}

void Calculator::update()
{
    const auto inputKey = userInputReader->readInputKey();

    interaction->handleMouseOverOnTilesLayout(*tiles, userInputReader->readMousePosition());

    if (inputKey == calculator::InputKey::MouseLeft)
    {
        interaction->handleMouseClickOnTilesLayout(*tiles, userInputReader->readMousePosition());
    }
    else if (inputKey ==calculator::InputKey::Escape)
    {
        closeWindow();
    }

	tiles->updateResult(Buffer::getWordsAsLine());
}

void Calculator::clearWindow()
{
	window->clear(sf::Color::White);
}

void Calculator::closeWindow()
{
    window->close();
}

void Calculator::drawWindow()
{
    tiles->draw(*window);
	window->display();
}
