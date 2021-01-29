#include "Interaction.h"


void Interaction::mouseOver(vectorOfTiles & tiles, sf::Vector2f mousePosition)
{
	for (auto & tile : tiles)
	{
		tile->getRect().setFillColor(sf::Color::White);
	}

	int tileIndex = 0;
	for (auto & tile : tiles)
	{
		if (tileIndex == (int)Characters::RESULT)
		{
			continue;
		}
		else if (isIntersecting(*tile, mousePosition))
		{
			tile->getRect().setFillColor(sf::Color(189, 189, 189, 255));
		}
		tileIndex++;
	}
}

void Interaction::mouseClick(vectorOfTiles & tiles, sf::Vector2f mousePosition, int actionKey)
{
	int tileIndex = 0;
	for (auto & tile : tiles)
	{
		if (isIntersecting(*tile, mousePosition) && actionKey == (int)Inputs::MOUSELEFT)
		{
			switch (tileIndex)
			{
			case (int)Characters::ZERO:
			case (int)Characters::ONE:
			case (int)Characters::TWO:
			case (int)Characters::THREE:
			case (int)Characters::FOUR:
			case (int)Characters::FIVE:
			case (int)Characters::SIX:
			case (int)Characters::SEVEN:
			case (int)Characters::EIGHT:
			case (int)Characters::NINE:
				handleNumbers(tile->getValue());
				break;
			case (int)Characters::PLUS:
			case (int)Characters::MINUS:
			case (int)Characters::MULTIPLICATION:
			case (int)Characters::DIVISION:
				handleSigns(tile->getValue());
				break;
			case (int)Characters::EQUALS:
				handleResult();
				break;
			case (int)Characters::DOT:
				handleDot(tile->getValue());
				break;
			case (int)Characters::CLEAR:
				handleClear();
				break;
			case(int)Characters::REMOVE:
				handleRemove();
				break;
			}
		}
		tileIndex++;
	}
}

bool Interaction::isIntersecting(Tile & tile, sf::Vector2f position)
{
	sf::Vector2f tilePosition = tile.getRect().getPosition();
	int tileWidth = tile.getWidth();
	int tileHeight = tile.getHeight();

	return (position.x >= tilePosition.x && position.x <= tilePosition.x + tileWidth &&
		position.y >= tilePosition.y && position.y <= tilePosition.y + tileHeight);
}

void Interaction::handleNumbers(std::string value)
{
	std::string currentWord = Buffer::getCurrentWord();

	if (currentWord == "0")
	{
		Buffer::clearCurrentWord();
		Buffer::addToExistingWord(value);
	}
	else if (currentWord == "+" || currentWord == "-" ||
		currentWord == "/" || currentWord == "x")
	{
		Buffer::addToNewWord(value);
	}
	else
	{
		Buffer::addToExistingWord(value);
	}

	Buffer::setCurrentWordResult(false);
}

void Interaction::handleSigns(std::string value)
{
	std::string currentWord = Buffer::getCurrentWord();

	if (currentWord == "" || currentWord == ".") return;

	if (currentWord == "+" || currentWord == "-" ||
		currentWord == "/" || currentWord == "x")
	{
		Buffer::clearCurrentWord();
		Buffer::addToExistingWord(value);
	}
	else
	{
		Buffer::addToNewWord(value);
	}

	Buffer::setCurrentWordResult(false);
}

void Interaction::handleDot(std::string value)
{
	std::string currentWord = Buffer::getCurrentWord();
	std::size_t foundDot = currentWord.find(".");

	if (foundDot == std::string::npos && currentWord != "+" && currentWord != "-" &&
		currentWord != "/" &&	currentWord != "x" && currentWord != "")
	{
		Buffer::addToExistingWord(value);
	Buffer::setCurrentWordResult(false);
	}
}

void Interaction::handleResult()
{
	std::string currentWord = Buffer::getCurrentWord();

	if (currentWord != "+" && currentWord != "-" &&
		currentWord != "/" && currentWord != "x")
	{
		std::string result = OperationSolver::solve(Buffer::getWords());
		Buffer::clearWords();
		Buffer::addToExistingWord(result);
		Buffer::setCurrentWordResult(true);
	}
}

void Interaction::handleClear()
{
	Buffer::clearWords();
	Buffer::setCurrentWordResult(false);
}

void Interaction::handleRemove()
{
	std::string currentWord = Buffer::getCurrentWord();

	if (!Buffer::isCurrentWordResult() && currentWord != "+" && currentWord != "-" && currentWord != "/" &&currentWord != "x" && currentWord != "")
	{
		Buffer::removeLastWord();
		Buffer::setCurrentWordResult(false);
	}
}


