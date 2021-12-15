cmake_minimum_required(VERSION 3.0)
project(ODE-Solver-Project)

set(CMAKE_CXX_STANDARD 17)

include_directories(header-files)
include_directories(source-files)
add_subdirectory(Google_tests)

include_directories(eigen)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB SOURCES  ${PROJECT_SOURCE_DIR}/source-files/*.cpp)
file(GLOB HEADERS  ${PROJECT_SOURCE_DIR}/header-files/*.h)


add_executable(ODE ${SOURCES} ${HEADERS})
add_executable(Google_Tests_run testing_files/testing_main.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main)