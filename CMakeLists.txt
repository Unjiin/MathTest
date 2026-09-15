cmake_minimum_required(VERSION 4.3)
project(MathTest)

set(CMAKE_CXX_STANDARD 20)

add_executable(MathTest MathTest/main.cpp
        Lib/task.cpp
        Lib/task.h)

# GoogleTest
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

# Отдельный исполняемый файл с тестами
add_executable(MathTests
        Tests/tests.cpp)

target_link_libraries(
        MathTests
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(MathTests)


