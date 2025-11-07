#pragma once
#include <string>
#include <vector>

namespace vix::ai::nlp
{

    struct Tokenizer
    {
        std::vector<std::string> tokenize(const std::string &s) const
        {
            return s.empty() ? std::vector<std::string>{} : std::vector<std::string>{s};
        }
    };

} // namespace vix::ai::nlp