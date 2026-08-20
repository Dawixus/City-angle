cmake_minimum_required(VERSION 4.2)

project(CityAngle)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)

include(FetchContent)

FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.12.0
)

FetchContent_MakeAvailable(json)

add_executable(CityAngle
        main.cpp
        Date.cpp
        Date.h
        Random.cpp
        Random.h
        Vec2.cpp
        Vec2.h
        City.cpp
        City.h
        Circle.cpp
        Circle.h
        FileReader.cpp
        FileReader.h
        Game.cpp
        Game.h
)

add_custom_command(TARGET CityAngle POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/cities.json
        $<TARGET_FILE_DIR:CityAngle>/cities.json
)

target_link_libraries(CityAngle
        PRIVATE
        nlohmann_json::nlohmann_json
        SDL2::SDL2
)