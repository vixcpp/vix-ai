#pragma once
#include <string>

namespace vix::ai::cli
{

    struct Commands
    {
        std::string help() const { return "vix ai <cmd>"; }
    };

} // namespace vix::ai::cli