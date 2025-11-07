#pragma once

namespace vix::ai::core
{
    inline constexpr const char *version() noexcept
    {
        return VIX_AI_CORE_VERSION; // provided by target_compile_definitions
    }
}