#include <iostream>
#include <vix/ai/core/Engine.hpp>

using namespace vix::ai::core;

int main()
{
    Engine e{Device::from_string("cpu")};
    std::cout << e.info() << "\n";
}
