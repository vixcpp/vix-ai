cmake_minimum_required(VERSION 3.20)

#[[
Vix.AI — Distributed Examples
Built only if Vix::AI::distributed is available.
]]

message(STATUS "Building Vix.AI.Distributed examples")

if (NOT TARGET Vix::AI::distributed)
  message(STATUS "Skipping Distributed examples (Vix::AI::distributed not found)")
  return()
endif()

add_executable(vix_ai_example_distrib_hello 01_hello.cpp)
target_link_libraries(vix_ai_example_distrib_hello PRIVATE Vix::AI::distributed)
target_compile_features(vix_ai_example_distrib_hello PRIVATE cxx_std_20)
