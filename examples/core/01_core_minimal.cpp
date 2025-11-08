#include <iostream>
#include <vix/ai/core/Version.hpp>
#include <vix/ai/core/Engine.hpp>
#include <vix/ai/core/Tensor.hpp>

using namespace vix::ai::core;

int main()
{
    std::cout << "vix_ai_core version: " << version() << "\n";
    Tensor t({2, 2, 2});
    Engine e{Device::from_string("cpu")};
    std::cout << e.compute(t) << "\n";
}
