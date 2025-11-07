#pragma once
#include <cstddef>
namespace vix::ai::nn::layers
{
    class Transformer
    {
    public:
        Transformer(std::size_t h = 8) : heads_(h) {}
        std::size_t heads() const { return heads_; }

    private:
        std::size_t heads_{};
    };
} // namespace vix::ai::nn::layers