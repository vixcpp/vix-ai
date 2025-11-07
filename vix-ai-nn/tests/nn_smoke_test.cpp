#include <cstdlib>
#include <iostream>
#include <vix/ai/nn/Network.hpp>
#include <vix/ai/nn/Layers/Dense.hpp>
#include <vix/ai/nn/Layers/Conv2D.hpp>
#include <vix/ai/nn/Layers/Transformer.hpp>
#include <vix/ai/nn/Optimizers/Adam.hpp>
#include <vix/ai/nn/Optimizers/SGD.hpp>

int main()
{
    using namespace vix::ai::nn;
    using namespace vix::ai::nn::layers;
    using namespace vix::ai::nn::opt;

    Network net;
    if (net.summary().empty())
        return EXIT_FAILURE;
    Dense d{4, 8};
    if (d.in_features() != 4 || d.out_features() != 8)
        return EXIT_FAILURE;
    Conv2D c{3};
    if (c.kernel() != 3)
        return EXIT_FAILURE;
    Transformer t{8};
    if (t.heads() != 8)
        return EXIT_FAILURE;
    Adam a;
    if (a.lr() <= 0)
        return EXIT_FAILURE;
    SGD s;
    if (s.lr() <= 0)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}