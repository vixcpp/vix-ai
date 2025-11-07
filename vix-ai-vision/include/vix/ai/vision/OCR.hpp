#pragma once
#include <string>
#include "Image.hpp"

namespace vix::ai::vision
{

    struct OCR
    {
        std::string recognize(const Image &) const { return {}; }
    };

} // namespace vix::ai::vision