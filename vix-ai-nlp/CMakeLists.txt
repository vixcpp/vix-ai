add_library(vix_ai_nlp
  src/Tokenizer.cpp
  src/Embedding.cpp
  src/Pipeline.cpp
  src/ModelLoader.cpp
)

add_library(Vix::AI::nlp ALIAS vix_ai_nlp)

target_link_libraries(vix_ai_nlp PUBLIC Vix::AI::core Vix::AI::nn)

target_include_directories(vix_ai_nlp PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_compile_features(vix_ai_nlp PUBLIC cxx_std_20)

option(VIX_AI_NLP_BUILD_TESTS "Build vix_ai_nlp tests" ON)
if (VIX_AI_NLP_BUILD_TESTS)
  add_subdirectory(tests)
endif()

include(GNUInstallDirs)
install(TARGETS vix_ai_nlp EXPORT vix_ai_nlpTargets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT vix_ai_nlpTargets FILE vix_ai_nlpTargets.cmake NAMESPACE Vix::AI:: DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vix_ai_nlp)