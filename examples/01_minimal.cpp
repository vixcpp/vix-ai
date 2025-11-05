#include <iostream>
#include <vix/ai/core/Version.hpp>
#include <vix/ai/core/Engine.hpp>
#include <vix/ai/core/Tensor.hpp>

int main()
{
    using namespace vix::ai::core;
    std::cout << "vix_ai_core version: " << version() << "\n";
    Engine engine{Device{}};    // CPU
    Tensor t{{1, 3, 224, 224}}; // NCHW fictif
    std::cout << "rank=" << t.rank() << ", msg=" << engine.compute(t) << "\n";
    return 0;
}
