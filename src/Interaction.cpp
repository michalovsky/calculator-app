#include "Interaction.h"

#include "InputKey.h"
#include "LayoutCharacter.h"
#include "TilesLayout.h"

using namespace calculator;

void Interaction::mouseOver(TilesLayout& tilesLayout, sf::Vector2f mousePosition)
{
    tilesLayout.changeTilesColor(sf::Color::White);

    const auto mouseOverColor = sf::Color(189, 189, 189, 255);
    tilesLayout.changeTilesColorOnIntersection(mouseOverColor, mousePosition);
}

void Interaction::mouseClick(TilesLayout & tilesLayout, sf::Vector2f mousePosition, int actionKey)
{
    if (actionKey != (int)InputKey::MouseLeft)
    {
        return;
    }

    if (const auto tileIntersectedInfo = tilesLayout.getInformationAboutTileBeingIntersected(mousePosition))
    {
        switch (tileIntersectedInfo->layoutCharacter)
        {
        case LayoutCharacter::Number0:
        case LayoutCharacter::Number1:
        case LayoutCharacter::Number2:
        case LayoutCharacter::Number3:
        case LayoutCharacter::Number4:
        case LayoutCharacter::Number5:
        case LayoutCharacter::Number6:
        case LayoutCharacter::Number7:
        case LayoutCharacter::Number8:
        case LayoutCharacter::Number9:
            handleNumbers(tileIntersectedInfo->text);
            break;
        case LayoutCharacter::Plus:
        case LayoutCharacter::Minus:
        case LayoutCharacter::Multiplication:
        case LayoutCharacter::Division:
            handleSigns(tileIntersectedInfo->text);
            break;
        case LayoutCharacter::Equal:
            handleResult();
            break;
        case LayoutCharacter::Dot:
            handleDot(tileIntersectedInfo->text);
            break;
        case LayoutCharacter::Clear:
            handleClear();
            break;
        case LayoutCharacter::Remove:
            handleRemove();
            break;
        }
    }
}

bool Interaction::isIntersecting(calculator::Tile & tile, sf::Vector2f position)
{
    return tile.isIntersecting(position);
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


