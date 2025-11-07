add_library(vix_ai_cli
  src/Commands.cpp
  src/TrainerCLI.cpp
)

add_library(Vix::AI::cli ALIAS vix_ai_cli)

target_link_libraries(vix_ai_cli PUBLIC Vix::AI::core)

target_include_directories(vix_ai_cli PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_compile_features(vix_ai_cli PUBLIC cxx_std_20)

option(VIX_AI_CLI_BUILD_TESTS "Build vix_ai_cli tests" ON)
if (VIX_AI_CLI_BUILD_TESTS)
  add_subdirectory(tests)
endif()

include(GNUInstallDirs)
install(TARGETS vix_ai_cli EXPORT vix_ai_cliTargets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT vix_ai_cliTargets FILE vix_ai_cliTargets.cmake NAMESPACE Vix::AI:: DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_cli)