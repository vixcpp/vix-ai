#pragma once
namespace vix::ai::nn::opt
{
    class Adam
    {
    public:
        double lr() const { return 0.001; }
    };
} // namespace vix::ai::nn::opt