cmake_minimum_required(VERSION 3.20)

#[[
===============================================================================
Vix AI - Umbrella CMake Project
===============================================================================
This is the top-level build configuration for the **Vix.AI** ecosystem.

It aggregates multiple AI-oriented C++ modules developed under the Vix project:
  • vix-ai-core         — Core tensor, device & engine primitives
  • vix-ai-ml           — Machine learning utilities and algorithms
  • vix-ai-nn           — Neural network primitives
  • vix-ai-nlp          — Natural language processing tools
  • vix-ai-vision       — Computer vision components
  • vix-ai-distributed  — Distributed / parallel computing
  • vix-ai-cli          — Developer command line interface

Each subproject can be built or skipped independently using -DVIX_AI_BUILD_* options.
This structure allows modular development and incremental builds while providing
a unified installation and package configuration (`find_package(vix_ai CONFIG)`).

Usage:
  cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -DVIX_AI_BUILD_CORE=ON
  cmake --build build
  cmake --install build --prefix /usr/local
===============================================================================
]]

project(vix_ai
  VERSION 0.1.0
  DESCRIPTION "Vix AI umbrella: core, ml, nn, nlp, vision, distributed, cli"
  LANGUAGES CXX)

include(CTest)

# ---- Global build options ---------------------------------------------------
option(VIX_AI_BUILD_EXAMPLES   "Build umbrella examples" ON)
option(VIX_AI_BUILD_CORE       "Build vix-ai-core"       ON)
option(VIX_AI_BUILD_ML         "Build vix-ai-ml"         OFF)
option(VIX_AI_BUILD_NN         "Build vix-ai-nn"         OFF)
option(VIX_AI_BUILD_NLP        "Build vix-ai-nlp"        OFF)
option(VIX_AI_BUILD_VISION     "Build vix-ai-vision"     OFF)
option(VIX_AI_BUILD_DISTRIB    "Build vix-ai-distributed" OFF)
option(VIX_AI_BUILD_CLI        "Build vix-ai-cli"        OFF)
option(VIX_AI_INSTALL          "Install umbrella package" ON)

# ---- Compiler configuration -------------------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
  add_compile_options(/W4 /permissive-)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(VIX_AI_VERSION ${PROJECT_VERSION})

# ---- Helper function for optional subdirectories ---------------------------
function(add_dir_if exists_flag dir opt_var)
  if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${dir}" AND ${opt_var})
    message(STATUS "Adding subdirectory: ${dir}")
    add_subdirectory(${dir})
  else()
    message(STATUS "Skipping ${dir} (missing or disabled)")
  endif()
endfunction()

# ---- Subprojects ------------------------------------------------------------
add_dir_if(exists_flag vix-ai-core        VIX_AI_BUILD_CORE)
add_dir_if(exists_flag vix-ai-ml          VIX_AI_BUILD_ML)
add_dir_if(exists_flag vix-ai-nn          VIX_AI_BUILD_NN)
add_dir_if(exists_flag vix-ai-nlp         VIX_AI_BUILD_NLP)
add_dir_if(exists_flag vix-ai-vision      VIX_AI_BUILD_VISION)
add_dir_if(exists_flag vix-ai-distributed VIX_AI_BUILD_DISTRIB)
add_dir_if(exists_flag vix-ai-cli         VIX_AI_BUILD_CLI)

if (VIX_AI_BUILD_EXAMPLES AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/examples")
  add_subdirectory(examples)
endif()

# ---- Meta target linking all available modules -----------------------------
add_library(vix_ai_all INTERFACE)
add_library(Vix::AI::all ALIAS vix_ai_all)

if (TARGET Vix::AI::core)
  target_link_libraries(vix_ai_all INTERFACE Vix::AI::core)
endif()
if (TARGET Vix::AI::ml)
  target_link_libraries(vix_ai_all INTERFACE Vix::AI::ml)
endif()
if (TARGET Vix::AI::nn)
  target_link_libraries(vix_ai_all INTERFACE Vix::AI::nn)
endif()
if (TARGET Vix::AI::nlp)
  target_link_libraries(vix_ai_all INTERFACE Vix::AI::nlp)
endif()
if (TARGET Vix::AI::vision)
  target_link_libraries(vix_ai_all INTERFACE Vix::AI::vision)
endif()
if (TARGET Vix::AI::distributed)
  target_link_libraries(vix_ai_all INTERFACE Vix::AI::distributed)
endif()
if (TARGET Vix::AI::cli)
  target_link_libraries(vix_ai_all INTERFACE Vix::AI::cli)
endif()

# ---- Installation and Package Export ---------------------------------------
if (VIX_AI_INSTALL)
  include(GNUInstallDirs)
  include(CMakePackageConfigHelpers)

  install(TARGETS vix_ai_all
    EXPORT vix_aiTargets
  )

  install(EXPORT vix_aiTargets
    FILE vix_aiTargets.cmake
    NAMESPACE Vix::AI::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai
  )

  write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/vix_aiConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
  )

  file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/vix_aiConfig.cmake
"include(\"\${CMAKE_CURRENT_LIST_DIR}/vix_aiTargets.cmake\")\n"
"# Load subpackage targets if installed\n"
"foreach(_comp IN ITEMS vix_ai_core vix_ai_ml vix_ai_nn vix_ai_nlp vix_ai_vision vix_ai_distributed vix_ai_cli)\n"
"  set(_p \"\${CMAKE_CURRENT_LIST_DIR}/../\${_comp}/\${_comp}Targets.cmake\")\n"
"  if (EXISTS \"\${_p}\")\n"
"    include(\"\${_p}\")\n"
"  endif()\n"
"endforeach()\n"
  )

  install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/vix_aiConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/vix_aiConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai
  )
endif()

# ---- Global testing placeholder --------------------------------------------
if (BUILD_TESTING)
  # add_subdirectory(tests)
endif()
