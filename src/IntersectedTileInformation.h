#pragma once

#include <string>

#include "LayoutCharacter.h"

namespace calculator
{
struct IntersectedTileInformation
{
    std::string text;
    calculator::LayoutCharacter layoutCharacter;
};
}