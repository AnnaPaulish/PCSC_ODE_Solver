cmake_minimum_required(VERSION 3.0)
project(ODE-Solver-Project)

set(CMAKE_CXX_STANDARD 17)

include_directories(header-files)
include_directories(source-files)

FILE(GLOB hHeaders *.h)
FILE(GLOB cppSources *.cpp)

add_executable(ODE main.cpp ${cppSources} ${hHeaders})