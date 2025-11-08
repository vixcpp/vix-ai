cmake_minimum_required(VERSION 3.20)

#[[
===============================================================================
Vix.AI — Core Examples
===============================================================================
This CMake script builds demonstration programs for the Core module of Vix.AI.

The Core module provides foundational abstractions:
  • Device  — hardware selection (CPU / CUDA)
  • Tensor  — lightweight multidimensional array
  • Engine  — execution and computation interface

These examples are always built as long as the Core library (Vix::AI::core)
exists in the current build graph.

===============================================================================
]]

#[[
Vix.AI — Core Examples
These demos illustrate Device/Tensor/Engine usage.
]]

message(STATUS "Building Vix.AI.Core examples")

if (NOT TARGET Vix::AI::core)
  message(WARNING "Skipping Core examples (Vix::AI::core not found)")
  return()
endif()

# 01 — minimal
add_executable(vix_ai_example_core_minimal 01_core_minimal.cpp)
target_link_libraries(vix_ai_example_core_minimal PRIVATE Vix::AI::core)
target_compile_features(vix_ai_example_core_minimal PRIVATE cxx_std_20)

# 02 — tensor demo (fill/reshape/compute)
add_executable(vix_ai_example_core_tensor_demo 02_tensor_demo.cpp)
target_link_libraries(vix_ai_example_core_tensor_demo PRIVATE Vix::AI::core)
target_compile_features(vix_ai_example_core_tensor_demo PRIVATE cxx_std_20)

# 03 — device parse & info
add_executable(vix_ai_example_core_device_parse 03_device_parse.cpp)
target_link_libraries(vix_ai_example_core_device_parse PRIVATE Vix::AI::core)
target_compile_features(vix_ai_example_core_device_parse PRIVATE cxx_std_20)

# 04 — engine info
add_executable(vix_ai_example_core_engine_info 04_engine_info.cpp)
target_link_libraries(vix_ai_example_core_engine_info PRIVATE Vix::AI::core)
target_compile_features(vix_ai_example_core_engine_info PRIVATE cxx_std_20)
