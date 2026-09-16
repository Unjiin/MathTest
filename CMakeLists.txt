cmake_minimum_required(VERSION 3.20)
project(MathTest)

set(CMAKE_CXX_STANDARD 20)

# =========================
# Статическая библиотека Lib
# =========================

add_library(Lib STATIC
        Lib/task.cpp
        Lib/task.h
        Lib/mathtest.cpp
        Lib/mathtest.h
)

target_include_directories(Lib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Lib
)

# =========================
# Основное приложение MathTest
# =========================

add_executable(MathTest
        MathTest/main.cpp
)

# Подключаем Lib к MathTest
target_link_libraries(MathTest PRIVATE Lib)


# =========================
# GoogleTest
# =========================

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()


# =========================
# Проект с тестами
# =========================

add_executable(MathTests
        Tests/tests.cpp
)

# Подключаем GoogleTest и нашу библиотеку Lib
target_link_libraries(
        MathTests
        GTest::gtest_main
        Lib
)

include(GoogleTest)
gtest_discover_tests(MathTests)