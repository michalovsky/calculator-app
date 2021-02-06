#include "Interaction.h"

#include "LayoutCharacter.h"
#include "InputKey.h"

using namespace calculator;

void Interaction::mouseOver(vectorOfTiles & tiles, sf::Vector2f mousePosition)
{
	for (auto & tile : tiles)
	{
		tile->getRect().setFillColor(sf::Color::White);
	}

	int tileIndex = 0;
	for (auto & tile : tiles)
	{
		if (tileIndex == (int)LayoutCharacter::Result)
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
		if (isIntersecting(*tile, mousePosition) && actionKey == (int)InputKey::MouseLeft)
		{
			switch (tileIndex)
			{
			case (int)LayoutCharacter::Number0:
			case (int)LayoutCharacter::Number1:
			case (int)LayoutCharacter::Number2:
			case (int)LayoutCharacter::Number3:
			case (int)LayoutCharacter::Number4:
			case (int)LayoutCharacter::Number5:
			case (int)LayoutCharacter::Number6:
			case (int)LayoutCharacter::Number7:
			case (int)LayoutCharacter::Number8:
			case (int)LayoutCharacter::Number9:
				handleNumbers(tile->getValue());
				break;
			case (int)LayoutCharacter::Plus:
			case (int)LayoutCharacter::Minus:
			case (int)LayoutCharacter::Multiplication:
			case (int)LayoutCharacter::Division:
				handleSigns(tile->getValue());
				break;
			case (int)LayoutCharacter::Equal:
				handleResult();
				break;
			case (int)LayoutCharacter::Dot:
				handleDot(tile->getValue());
				break;
			case (int)LayoutCharacter::Clear:
				handleClear();
				break;
			case(int)LayoutCharacter::Remove:
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


