#pragma once
#include <string>

namespace vix::ai::cli
{

    struct TrainerCLI
    {
        std::string run(const std::string & /*cmd*/) { return "ok"; }
    };

} // namespace vix::ai::cli