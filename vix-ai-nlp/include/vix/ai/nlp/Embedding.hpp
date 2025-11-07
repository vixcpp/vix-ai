#pragma once
#include <string>
#include <vector>

namespace vix::ai::nlp
{

    struct Embedding
    {
        std::vector<float> encode(const std::string &s) const
        {
            return {static_cast<float>(s.size())}; // factice
        }
    };

} // namespace vix::ai::nlp