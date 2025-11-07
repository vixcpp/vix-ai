#pragma once
#include <cstddef>

namespace vix::ai::distributed
{

    struct FederatedTrainer
    {
        std::size_t round{0};
        void step() { ++round; }
    };

} // namespace vix::ai::distributed