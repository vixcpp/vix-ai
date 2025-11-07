#pragma once
#include <cstddef>
#include <vector>

namespace vix::ai::vision
{

    struct Image
    {
        std::size_t w{};
        std::size_t h{}; // pas de pixels (squelette)
    };

} // namespace vix::ai::vision