#include <iostream>
#include <vix/ai/core/Engine.hpp>
#include <vix/ai/ml/Dataset.hpp>
#include <vix/ai/ml/LinearRegression.hpp> // ensures LinearRegression with Model API

int main()
{
    using namespace vix::ai::core;
    using namespace vix::ai::ml;

    Engine engine{Device{}};
    std::cout << engine.compute({}) << " ";

    // Dataset fields order: X, y, U
    Dataset ds;
    ds.X = {{0.0}, {1.0}, {2.0}, {3.0}}; // one feature column
    ds.y = {1.0, 3.0, 5.0, 7.0};

    std::cout << "dataset size=" << ds.size_supervised() << " ";

    LinearRegression lr{2.0, 1.0}; // y ≈ 2x + 1

    // Option 1: scalar helper (non-virtual)
    std::cout << "predict(4)=" << lr.predict_scalar(4.0) << " (attendu ~9)\n";

    // Option 2: via base interface
    // Mat Xtest{{4.0}};
    // std::cout << "predict(4)=" << lr.predict(Xtest)[0] << " (attendu ~9)\n";

    return 0;
}
