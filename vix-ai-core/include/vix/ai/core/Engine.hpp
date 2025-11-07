#pragma once
#include <string>
#include <memory>
#include "Tensor.hpp"
#include "Device.hpp"

namespace vix::ai::core
{

    class Engine
    {
    public:
        Engine() = default;
        explicit Engine(Device dev) : device_(std::move(dev)) {}

        const Device &device() const noexcept { return device_; }

        // hyper basique: "compute" renvoie une string informative
        std::string compute(const Tensor &t) const
        {
            (void)t; // unused for now
            return std::string{"Engine["} + device().name() + "] ok";
        }

    private:
        Device device_{}; // default CPU
    };

} // namespace vix::ai::core