#pragma once
#include <string>

namespace vix::ai::nlp
{

    class Pipeline
    {
    public:
        std::string summarize(const std::string &s) const { return s; }
    };

} // namespace vix::ai::nlp