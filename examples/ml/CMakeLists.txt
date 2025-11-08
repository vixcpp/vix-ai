cmake_minimum_required(VERSION 3.20)

#[[
===============================================================================
Vix.AI — ML Examples
===============================================================================
This CMake script builds demonstration programs for the Machine Learning module.

Notes:
  - Examples here are only built if the ML target (Vix::AI::ml) is present.
  - They optionally link against Vix::AI::core when available.

===============================================================================
]]

message(STATUS "Building Vix.AI.ML examples")

# Build only if ML module is available
if (NOT TARGET Vix::AI::ml)
  message(STATUS "Skipping ML examples (Vix::AI::ml not found)")
  return()
endif()

# Example: regression + clustering (02_regression_kmeans.cpp)
add_executable(vix_ai_example_ml_regression_kmeans 02_regression_kmeans.cpp)
target_compile_features(vix_ai_example_ml_regression_kmeans PRIVATE cxx_std_20)

# Always link ML; link Core if present
target_link_libraries(vix_ai_example_ml_regression_kmeans
  PRIVATE
    Vix::AI::ml
)

if (TARGET Vix::AI::core)
  target_link_libraries(vix_ai_example_ml_regression_kmeans
    PRIVATE
      Vix::AI::core
  )
endif()
