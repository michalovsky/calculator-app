#pragma once

#include "LayoutCharacter.h"
#include <string>

namespace calculator
{
struct IntersectedTileInformation
{
    std::string text;
    calculator::LayoutCharacter layoutCharacter;
};
}