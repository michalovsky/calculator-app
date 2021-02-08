#include "IntersectedTileInformationInterpreter.h"

#include <algorithm>

#include "OperationSolver.h"

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

IntersectedTileInformationInterpreter::IntersectedTileInformationInterpreter(
    std::shared_ptr<Buffer> bufferInit, std::unique_ptr<OperationSolver> operationSolverInit)
    : buffer{std::move(bufferInit)}, operationSolver{std::move(operationSolverInit)}
{
}

void IntersectedTileInformationInterpreter::interpretTileInformation(
    const IntersectedTileInformation& tileIntersectedInfo)
{
    const auto& layoutCharacter = tileIntersectedInfo.layoutCharacter;
    if (layoutCharacterIsNumber(layoutCharacter))
    {
        handleNumbers(tileIntersectedInfo.text);
    }
    else if (layoutCharacterIsOperationSign(layoutCharacter))
    {
        handleSigns(tileIntersectedInfo.text);
    }
    else if (layoutCharacterIsResultSign(layoutCharacter))
    {
        handleResult();
    }
    else if (layoutCharacterIsDot(layoutCharacter))
    {
        handleDot(tileIntersectedInfo.text);
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

bool IntersectedTileInformationInterpreter::layoutCharacterIsNumber(LayoutCharacter layoutCharacter)
{
    return std::any_of(layoutNumbers.begin(), layoutNumbers.end(),
                       [&](LayoutCharacter layoutNumber) { return layoutCharacter == layoutNumber; });
}

bool IntersectedTileInformationInterpreter::layoutCharacterIsOperationSign(LayoutCharacter layoutCharacter)
{
    return std::any_of(
        layoutOperationSigns.begin(), layoutOperationSigns.end(),
        [&](LayoutCharacter layoutOperationSign) { return layoutCharacter == layoutOperationSign; });
}

bool IntersectedTileInformationInterpreter::layoutCharacterIsResultSign(LayoutCharacter layoutCharacter)
{
    return layoutCharacter == LayoutCharacter::Equal;
}

bool IntersectedTileInformationInterpreter::layoutCharacterIsDot(LayoutCharacter layoutCharacter)
{
    return layoutCharacter == LayoutCharacter::Dot;
}

bool IntersectedTileInformationInterpreter::layoutCharacterIsClear(LayoutCharacter layoutCharacter)
{
    return layoutCharacter == LayoutCharacter::Clear;
}

bool IntersectedTileInformationInterpreter::layoutCharacterIsRemove(LayoutCharacter layoutCharacter)
{
    return layoutCharacter == LayoutCharacter::Remove;
}

void IntersectedTileInformationInterpreter::handleNumbers(const std::string& value)
{
    const std::string currentWord = buffer->getCurrentWord();

    if (currentWord == "0")
    {
        buffer->clearCurrentWord();
        buffer->addToExistingWord(value);
    }
    else if (currentWordIsOperationSign(currentWord))
    {
        buffer->addToNewWord(value);
    }
    else
    {
        buffer->addToExistingWord(value);
    }

    buffer->setCurrentWordAsResult(false);
}

void IntersectedTileInformationInterpreter::handleSigns(const std::string& value)
{
    const auto currentWord = buffer->getCurrentWord();

    if (currentWord.empty() || currentWord == dotSign)
        return;

    if (currentWordIsOperationSign(currentWord))
    {
        buffer->clearCurrentWord();
        buffer->addToExistingWord(value);
    }
    else
    {
        buffer->addToNewWord(value);
    }

    buffer->setCurrentWordAsResult(false);
}

void IntersectedTileInformationInterpreter::handleDot(const std::string& value)
{
    const auto currentWord = buffer->getCurrentWord();
    const auto foundDot = currentWord.find(dotSign);

    if (foundDot == std::string::npos && not currentWord.empty() &&
        not currentWordIsOperationSign(currentWord))
    {
        buffer->addToExistingWord(value);
        buffer->setCurrentWordAsResult(false);
    }
}

void IntersectedTileInformationInterpreter::handleResult()
{
    const auto currentWord = buffer->getCurrentWord();

    if (not currentWordIsOperationSign(currentWord))
    {
        const auto result = operationSolver->solve(buffer->getWords());
        buffer->clearWords();
        buffer->addToExistingWord(result);
        buffer->setCurrentWordAsResult(true);
    }
}

void IntersectedTileInformationInterpreter::handleClear()
{
    buffer->clearWords();
    buffer->setCurrentWordAsResult(false);
}

void IntersectedTileInformationInterpreter::handleRemove()
{
    const auto currentWord = buffer->getCurrentWord();

    if (!buffer->isCurrentWordResult() && not currentWord.empty() &&
        not currentWordIsOperationSign(currentWord))
    {
        buffer->removeLastWord();
        buffer->setCurrentWordAsResult(false);
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