cmake_minimum_required(VERSION 3.0)
project(ODE-Solver-Project)

set(CMAKE_CXX_STANDARD 17)

include_directories(header-files)
include_directories(source-files)

include_directories(eigen)

file(GLOB SOURCES  ${PROJECT_SOURCE_DIR}/source-files/*.cpp)
file(GLOB HEADERS  ${PROJECT_SOURCE_DIR}/header-files/*.h)


add_executable(ODE main.cpp ${SOURCES} ${HEADERS})