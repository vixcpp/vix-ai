#pragma once
#include <cstddef>
#include <vector>

namespace vix::ai::core
{

    class Tensor
    {
    public:
        Tensor() = default;
        explicit Tensor(std::vector<std::size_t> shape)
            : shape_(std::move(shape)) {}

        const std::vector<std::size_t> &shape() const noexcept { return shape_; }
        std::size_t rank() const noexcept { return shape_.size(); }

    private:
        std::vector<std::size_t> shape_{};
    };

} // namespace vix::ai::core