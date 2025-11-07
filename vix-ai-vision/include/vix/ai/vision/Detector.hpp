#pragma once
#include <vector>
#include <array>
#include "Image.hpp"

namespace vix::ai::vision
{

    struct Detector
    {
        // renvoie N boxes factices: {x,y,w,h}
        std::vector<std::array<int, 4>> detect(const Image &) const { return {}; }
    };

} // namespace vix::ai::vision