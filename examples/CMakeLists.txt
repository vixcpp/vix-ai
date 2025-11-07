# vix-ai/examples/CMakeLists.txt

cmake_minimum_required(VERSION 3.20)

message(STATUS "Building Vix.AI examples")

# Example 1: minimal setup
add_executable(vix_ai_example_01 01_minimal.cpp)
target_link_libraries(vix_ai_example_01 PRIVATE Vix::AI::core)
target_compile_features(vix_ai_example_01 PRIVATE cxx_std_20)

# Example 2: minimal ML demo (simple regression)
add_executable(vix_ai_example_02_ml_minimal 02_ml_minimal.cpp)
target_link_libraries(vix_ai_example_02_ml_minimal PRIVATE Vix::AI::core Vix::AI::ml)
target_compile_features(vix_ai_example_02_ml_minimal PRIVATE cxx_std_20)

# Add subdirectory for ML-specific examples
add_subdirectory(ml)
