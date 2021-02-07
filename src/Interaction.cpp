#include "Interaction.h"

#include "LayoutCharacter.h"
#include "TilesLayout.h"

namespace calculator
{
namespace
{
std::vector<LayoutCharacter> layoutNumbers{
    LayoutCharacter::Number0, LayoutCharacter::Number1, LayoutCharacter::Number2, LayoutCharacter::Number3,
    LayoutCharacter::Number4, LayoutCharacter::Number5, LayoutCharacter::Number6, LayoutCharacter::Number7,
    LayoutCharacter::Number8, LayoutCharacter::Number9};

std::vector<LayoutCharacter> layoutOperationSigns{LayoutCharacter::Plus, LayoutCharacter::Minus,
                                                  LayoutCharacter::Multiplication, LayoutCharacter::Division};

bool currentWordIsOperationSign(const std::string& currentWord);

const auto plusSign = "+";
const auto minusSign = "-";
const auto multiplicationSign = "x";
const auto divisionSign = "/";
const auto dotSign = ".";
}

void Interaction::handleMouseOverOnTilesLayout(TilesLayout& tilesLayout, sf::Vector2f mousePosition)
{
    tilesLayout.changeTilesColor(sf::Color::White);

    const auto mouseOverColor = sf::Color(189, 189, 189, 255);
    tilesLayout.changeTilesColorOnIntersection(mouseOverColor, mousePosition);
}

void Interaction::handleMouseClickOnTilesLayout(TilesLayout& tilesLayout, sf::Vector2f mousePosition)
{
    if (const auto tileIntersectedInfo = tilesLayout.getInformationAboutTileBeingIntersected(mousePosition))
    {
        const auto& layoutCharacter = tileIntersectedInfo->layoutCharacter;
        if (layoutCharacterIsNumber(layoutCharacter))
        {
            handleNumbers(tileIntersectedInfo->text);
        }
        else if (layoutCharacterIsOperationSign(layoutCharacter))
        {
            handleSigns(tileIntersectedInfo->text);
        }
        else if (layoutCharacterIsResultSign(layoutCharacter))
        {
            handleResult();
        }
        else if (layoutCharacterIsDot(layoutCharacter))
        {
            handleDot(tileIntersectedInfo->text);
        }
        else if (layoutCharacterIsClear(layoutCharacter))
        {
            handleClear();
        }
        else if (layoutCharacterIsRemove(layoutCharacter))
        {
            handleRemove();
        }
    }
}

bool Interaction::layoutCharacterIsNumber(LayoutCharacter layoutCharacter)
{
    return std::any_of(layoutNumbers.begin(), layoutNumbers.end(),
                       [&](LayoutCharacter layoutNumber) { return layoutCharacter == layoutNumber; });
}

bool Interaction::layoutCharacterIsOperationSign(LayoutCharacter layoutCharacter)
{
    return std::any_of(
        layoutOperationSigns.begin(), layoutOperationSigns.end(),
        [&](LayoutCharacter layoutOperationSign) { return layoutCharacter == layoutOperationSign; });
}

bool Interaction::layoutCharacterIsResultSign(LayoutCharacter layoutCharacter)
{
    return layoutCharacter == LayoutCharacter::Equal;
}

bool Interaction::layoutCharacterIsDot(LayoutCharacter layoutCharacter)
{
    return layoutCharacter == LayoutCharacter::Dot;
}

bool Interaction::layoutCharacterIsClear(LayoutCharacter layoutCharacter)
{
    return layoutCharacter == LayoutCharacter::Clear;
}

bool Interaction::layoutCharacterIsRemove(LayoutCharacter layoutCharacter)
{
    return layoutCharacter == LayoutCharacter::Remove;
}

void Interaction::handleNumbers(const std::string& value)
{
    std::string currentWord = Buffer::getCurrentWord();

    if (currentWord == "0")
    {
        Buffer::clearCurrentWord();
        Buffer::addToExistingWord(value);
    }
    else if (currentWordIsOperationSign(currentWord))
    {
        Buffer::addToNewWord(value);
    }
    else
    {
        Buffer::addToExistingWord(value);
    }

    Buffer::setCurrentWordResult(false);
}

void Interaction::handleSigns(const std::string& value)
{
    std::string currentWord = Buffer::getCurrentWord();

    if (currentWord.empty() || currentWord == dotSign)
        return;

    if (currentWordIsOperationSign(currentWord))
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

void Interaction::handleDot(const std::string& value)
{
    std::string currentWord = Buffer::getCurrentWord();
    std::size_t foundDot = currentWord.find(dotSign);

    if (foundDot == std::string::npos && not currentWord.empty() &&
        not currentWordIsOperationSign(currentWord))
    {
        Buffer::addToExistingWord(value);
        Buffer::setCurrentWordResult(false);
    }
}

void Interaction::handleResult()
{
    std::string currentWord = Buffer::getCurrentWord();

    if (not currentWordIsOperationSign(currentWord))
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

    if (!Buffer::isCurrentWordResult() && not currentWord.empty() &&
        not currentWordIsOperationSign(currentWord))
    {
        Buffer::removeLastWord();
        Buffer::setCurrentWordResult(false);
    }
}

namespace
{
bool currentWordIsOperationSign(const std::string& currentWord)
{
    return currentWord == plusSign || currentWord == minusSign || currentWord == divisionSign ||
           currentWord == multiplicationSign;
}
}

}
