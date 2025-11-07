#pragma once
#include <string>

namespace vix::ai::core
{

    enum class DeviceType
    {
        CPU,
        CUDA
    };

    class Device
    {
    public:
        explicit Device(DeviceType type = DeviceType::CPU) : type_(type) {}
        DeviceType type() const noexcept { return type_; }
        std::string name() const { return type_ == DeviceType::CPU ? "cpu" : "cuda"; }

    private:
        DeviceType type_{};
    };

} // namespace vix::ai::core