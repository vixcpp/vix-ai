#pragma once
#include <cstddef>
namespace vix::ai::nn::layers
{
    class Conv2D
    {
    public:
        Conv2D(std::size_t k = 3) : k_(k) {}
        std::size_t kernel() const { return k_; }

    private:
        std::size_t k_{};
    };
} // namespace vix::ai::nn::layers