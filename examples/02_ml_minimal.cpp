#include <iostream>
#include <vix/ai/core/Engine.hpp>
#include <vix/ai/ml/Dataset.hpp>
#include <vix/ai/ml/LinearRegression.hpp>

int main()
{
    using namespace vix::ai::core;
    using namespace vix::ai::ml;

    Engine engine{Device{}};
    std::cout << engine.compute({}) << " ";

    Dataset ds{/*x=*/{0.0, 1.0, 2.0, 3.0}, /*y=*/{1.0, 3.0, 5.0, 7.0}, /*X=*/{}};
    std::cout << "dataset size=" << ds.size_supervised() << " ";

    LinearRegression lr{2.0, 1.0}; // y ≈ 2x + 1
    std::cout << "predict(4)=" << lr.predict(4.0) << " (attendu ~9)";
    return 0;
}
