add_executable(vix_ai_example_01 01_minimal.cpp)
target_link_libraries(vix_ai_example_01 PRIVATE Vix::AI::core)
target_compile_features(vix_ai_example_01 PRIVATE cxx_std_20)

add_executable(vix_ai_example_02_ml 02_ml_minimal.cpp)
target_link_libraries(vix_ai_example_02_ml PRIVATE Vix::AI::core Vix::AI::ml)
target_compile_features(vix_ai_example_02_ml PRIVATE cxx_std_20)