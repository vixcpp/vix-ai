# vix-ai/examples/ml/CMakeLists.txt

cmake_minimum_required(VERSION 3.20)

message(STATUS "Building Vix.AI.ML examples")

# Example: regression + clustering (02_regression_kmeans.cpp)
add_executable(vix_ai_example_ml_regression_kmeans 02_regression_kmeans.cpp)
target_link_libraries(vix_ai_example_ml_regression_kmeans PRIVATE Vix::AI::ml)
target_compile_features(vix_ai_example_ml_regression_kmeans PRIVATE cxx_std_20)
