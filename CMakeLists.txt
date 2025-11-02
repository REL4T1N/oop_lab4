cmake_minimum_required(VERSION 3.14)
project(lab4_templates)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Установка Google Test через FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
  TLS_VERIFY false
)
FetchContent_MakeAvailable(googletest)

# Основная программа (только main.cpp, остальное в заголовочных)
add_executable(lab4_templates 
    main.cpp
)
target_include_directories(lab4_templates PRIVATE include)

# Тесты (только тестовые файлы, реализации в заголовочных)
add_executable(tests 
    tests/main_test.cpp
    tests/point_test.cpp
    tests/figure_test.cpp
    tests/pentagon_test.cpp
    tests/hexagon_test.cpp
    tests/octagon_test.cpp
    tests/array_test.cpp
)
target_include_directories(tests PRIVATE include)
target_link_libraries(tests gtest gtest_main)

# Добавление тестов в CTest
enable_testing()
add_test(NAME lab4_tests COMMAND tests)