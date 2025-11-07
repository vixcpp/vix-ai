#pragma once
#include <string>

namespace vix::ai::distributed
{

    struct SecureChannel
    {
        bool handshake(const std::string &) { return true; }
    };

} // namespace vix::ai::distributed