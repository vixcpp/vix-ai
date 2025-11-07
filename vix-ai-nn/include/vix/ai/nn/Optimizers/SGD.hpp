#pragma once
namespace vix::ai::nn::opt
{
    class SGD
    {
    public:
        double lr() const { return 0.01; }
    };
} // namespace vix::ai::nn::opt