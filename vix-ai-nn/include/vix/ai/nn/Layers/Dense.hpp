#pragma once
#include <cstddef>
namespace vix::ai::nn::layers
{
    class Dense
    {
    public:
        Dense(std::size_t in = 0, std::size_t out = 0) : in_(in), out_(out) {}
        std::size_t in_features() const { return in_; }
        std::size_t out_features() const { return out_; }

    private:
        std::size_t in_{};
        std::size_t out_{};
    };
} // namespace vix::ai::nn::layers