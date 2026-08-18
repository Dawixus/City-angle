cmake_minimum_required(VERSION 4.2)
project(CityAngle)

set(CMAKE_CXX_STANDARD 26)

find_package(SDL2 REQUIRED)

add_executable(CityAngle main.cpp)

target_link_libraries(CityAngle PRIVATE SDL2::SDL2)
