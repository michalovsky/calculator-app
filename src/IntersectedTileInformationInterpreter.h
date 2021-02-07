#pragma once

#include <memory>

#include "Buffer.h"
#include "IntersectedTileInformation.h"
#include "OperationSolver.h"

namespace calculator
{
class IntersectedTileInformationInterpreter
{
public:
    IntersectedTileInformationInterpreter(std::shared_ptr<Buffer>, std::unique_ptr<OperationSolver>);

    void interpretTileInformation(const IntersectedTileInformation&);

private:
    bool layoutCharacterIsNumber(LayoutCharacter);
    bool layoutCharacterIsOperationSign(LayoutCharacter);
    bool layoutCharacterIsResultSign(LayoutCharacter);
    bool layoutCharacterIsDot(LayoutCharacter);
    bool layoutCharacterIsClear(LayoutCharacter);
    bool layoutCharacterIsRemove(LayoutCharacter);
    void handleNumbers(const std::string& value);
    void handleSigns(const std::string& value);
    void handleResult();
    void handleDot(const std::string& value);
    void handleClear();
    void handleRemove();

    std::shared_ptr<Buffer> buffer;
    std::unique_ptr<OperationSolver> operationSolver;
};
}