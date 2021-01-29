#include "Input.h"


int Input::read(sf::RenderWindow & window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
		{
			return (int)Inputs::MOUSELEFT;

		}
		else if ((event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) || event.type == sf::Event::Closed)
		{
			return (int)Inputs::ESCAPE;
		}
	}

	return (int)Inputs::NO_INPUT;
}

sf::Vector2f Input::readMousePosition(sf::RenderWindow & window)
{
	return sf::Vector2f(sf::Mouse::getPosition(window));
}

