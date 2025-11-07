#pragma once
#include <string>

namespace vix::ai::nlp
{

    struct ModelLoader
    {
        bool load(const std::string & /*path*/) { return true; }
    };

} // namespace vix::ai::nlp