#pragma once

#include <stdexcept>

namespace calculator::exceptions
{
struct CannotAccessFontFile : std::runtime_error
{
    using std::runtime_error::runtime_error;
};
}
