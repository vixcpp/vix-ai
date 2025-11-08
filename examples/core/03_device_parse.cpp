#include <iostream>
#include <vector>
#include <vix/ai/core/Device.hpp>

using namespace vix::ai::core;

int main()
{
    std::vector<std::string> devs = {"cpu", "cuda", "cuda:1"};
    for (auto &s : devs)
    {
        Device d = Device::from_string(s);
        std::cout << "Parsed \"" << s << "\" -> " << d.name() << "\n";
    }
}
