#pragma once

#include <stdexcept>

namespace calculator::exceptions
{
struct LayoutCharacterNotFound : std::runtime_error
{
    using std::runtime_error::runtime_error;
};
}