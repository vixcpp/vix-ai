cmake_minimum_required(VERSION 3.20)
project(vix_ai LANGUAGES CXX)

include(CTest)

# Options
option(VIX_AI_BUILD_EXAMPLES "Build examples" ON)

# Global C++ standard and warnings (safe defaults)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
  add_compile_options(/W4 /permissive-)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_subdirectory(vix-ai-core)
add_subdirectory(vix-ai-ml)
add_subdirectory(vix-ai-nn)
add_subdirectory(vix-ai-nlp)
add_subdirectory(vix-ai-vision)
add_subdirectory(vix-ai-distributed)
add_subdirectory(vix-ai-cli)
  
if (VIX_AI_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()

