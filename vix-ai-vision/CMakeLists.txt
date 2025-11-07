add_library(vix_ai_vision
  src/Image.cpp
  src/Detector.cpp
  src/OCR.cpp
  src/Tracker.cpp
)

add_library(Vix::AI::vision ALIAS vix_ai_vision)

target_link_libraries(vix_ai_vision PUBLIC Vix::AI::core Vix::AI::nn)

target_include_directories(vix_ai_vision PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_compile_features(vix_ai_vision PUBLIC cxx_std_20)

option(VIX_AI_VISION_BUILD_TESTS "Build vix_ai_vision tests" ON)
if (VIX_AI_VISION_BUILD_TESTS)
  add_subdirectory(tests)
endif()

include(GNUInstallDirs)
install(TARGETS vix_ai_vision EXPORT vix_ai_visionTargets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT vix_ai_visionTargets FILE vix_ai_visionTargets.cmake NAMESPACE Vix::AI:: DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_vision)