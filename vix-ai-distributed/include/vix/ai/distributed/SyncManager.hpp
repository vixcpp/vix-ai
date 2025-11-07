#pragma once
#include <cstddef>

namespace vix::ai::distributed
{

    struct SyncManager
    {
        std::size_t sync() { return 0; }
    };

} // namespace vix::ai::distributed