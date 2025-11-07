# Core library
add_library(vix_ai_core
  src/Version.cpp
  src/Tensor.cpp
  src/Device.cpp
  src/Engine.cpp
)

add_library(Vix::AI::core ALIAS vix_ai_core)

# Public headers
target_include_directories(vix_ai_core
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Compile features
target_compile_features(vix_ai_core PUBLIC cxx_std_20)

# Simple compile definitions (version)
set(VIX_AI_CORE_VERSION "0.1.0")
target_compile_definitions(vix_ai_core PUBLIC VIX_AI_CORE_VERSION="${VIX_AI_CORE_VERSION}")

# Install rules (optional but nice)
include(GNUInstallDirs)
install(TARGETS vix_ai_core
  EXPORT vix_ai_coreTargets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT vix_ai_coreTargets
  FILE vix_ai_coreTargets.cmake
  NAMESPACE Vix::AI::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_core
)