#pragma once
#include <cstddef>
#include "Image.hpp"

namespace vix::ai::vision
{

    struct Tracker
    {
        std::size_t update(const Image &) { return 0; }
    };

} // namespace vix::ai::vision