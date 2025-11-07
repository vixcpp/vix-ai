#pragma once
#include <string>
#include <vector>

namespace vix::ai::nn
{

    class Network
    {
    public:
        Network() = default;
        std::string summary() const { return "Network[0 layers]"; }
    };

} // namespace vix::ai::nn