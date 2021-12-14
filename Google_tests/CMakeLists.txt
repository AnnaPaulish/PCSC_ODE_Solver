set(CMAKE_CXX_STANDARD 17)

project(Google_tests)

add_subdirectory(lib)
include_directories(../eigen)
include_directories(../header-files)
include_directories(../source-files)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run test_forward_euler.cpp)# implicitly also test the setup
target_link_libraries(Google_Tests_run gtest gtest_main)
