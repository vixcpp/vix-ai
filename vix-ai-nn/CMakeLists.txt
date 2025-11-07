add_library(vix_ai_nn
  src/Network.cpp
  src/Layers/Dense.cpp
  src/Layers/Conv2D.cpp
  src/Layers/Transformer.cpp
  src/Optimizers/Adam.cpp
  src/Optimizers/SGD.cpp
)

add_library(Vix::AI::nn ALIAS vix_ai_nn)

target_link_libraries(vix_ai_nn PUBLIC Vix::AI::core)

target_include_directories(vix_ai_nn PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_compile_features(vix_ai_nn PUBLIC cxx_std_20)

option(VIX_AI_NN_BUILD_TESTS "Build vix_ai_nn tests" ON)
if (VIX_AI_NN_BUILD_TESTS)
  add_subdirectory(tests)
endif()

include(GNUInstallDirs)
install(TARGETS vix_ai_nn EXPORT vix_ai_nnTargets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT vix_ai_nnTargets FILE vix_ai_nnTargets.cmake NAMESPACE Vix::AI:: DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_nn)