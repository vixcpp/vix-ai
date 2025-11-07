add_library(vix_ai_distributed
  src/Peer.cpp
  src/FederatedTrainer.cpp
  src/SecureChannel.cpp
  src/SyncManager.cpp
)

add_library(Vix::AI::distributed ALIAS vix_ai_distributed)

target_link_libraries(vix_ai_distributed PUBLIC Vix::AI::core)

target_include_directories(vix_ai_distributed PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_compile_features(vix_ai_distributed PUBLIC cxx_std_20)

option(VIX_AI_DISTRIBUTED_BUILD_TESTS "Build vix_ai_distributed tests" ON)
if (VIX_AI_DISTRIBUTED_BUILD_TESTS)
  add_subdirectory(tests)
endif()

include(GNUInstallDirs)
install(TARGETS vix_ai_distributed EXPORT vix_ai_distributedTargets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT vix_ai_distributedTargets FILE vix_ai_distributedTargets.cmake NAMESPACE Vix::AI:: DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_distributed)