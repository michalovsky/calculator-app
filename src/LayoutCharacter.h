#pragma once

#include <string>
#include <unordered_map>

#include "exceptions/LayoutCharacterNotFound.h"

namespace calculator
{
enum class LayoutCharacter
{
    Number0,
    Number1,
    Number2,
    Number3,
    Number4,
    Number5,
    Number6,
    Number7,
    Number8,
    Number9,
    Plus,
    Minus,
    Multiplication,
    Division,
    Equal,
    Remove,
    Clear,
    Dot
};

const std::vector<LayoutCharacter> allLayoutCharacters{
    LayoutCharacter::Number0,        LayoutCharacter::Number1,  LayoutCharacter::Number2,
    LayoutCharacter::Number3,        LayoutCharacter::Number4,  LayoutCharacter::Number5,
    LayoutCharacter::Number6,        LayoutCharacter::Number7,  LayoutCharacter::Number8,
    LayoutCharacter::Number9,        LayoutCharacter::Plus,     LayoutCharacter::Minus,
    LayoutCharacter::Multiplication, LayoutCharacter::Division, LayoutCharacter::Equal,
    LayoutCharacter::Remove,         LayoutCharacter::Clear,    LayoutCharacter::Dot};

inline std::string toString(LayoutCharacter layoutCharacter)
{
    std::unordered_map<LayoutCharacter, std::string> layoutCharacterToString{
        {LayoutCharacter::Number0, "0"},        {LayoutCharacter::Number1, "1"},
        {LayoutCharacter::Number2, "2"},        {LayoutCharacter::Number3, "3"},
        {LayoutCharacter::Number4, "4"},        {LayoutCharacter::Number5, "5"},
        {LayoutCharacter::Number6, "6"},        {LayoutCharacter::Number7, "7"},
        {LayoutCharacter::Number8, "8"},        {LayoutCharacter::Number9, "9"},
        {LayoutCharacter::Plus, "+"},           {LayoutCharacter::Minus, "-"},
        {LayoutCharacter::Multiplication, "x"}, {LayoutCharacter::Division, "/"},
        {LayoutCharacter::Equal, "="},          {LayoutCharacter::Remove, "<-"},
        {LayoutCharacter::Clear, "C"},          {LayoutCharacter::Dot, "."}};

    try
    {
        return layoutCharacterToString.at(layoutCharacter);
    }
    catch (const std::out_of_range& e)
    {
        throw exceptions::LayoutCharacterNotFound{e.what()};
    }
}
}
