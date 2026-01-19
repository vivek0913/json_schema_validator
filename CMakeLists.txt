cmake_minimum_required(VERSION 3.10)
project(JSON_VALIDATOR)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(nlohmann_json REQUIRED)

add_executable(JSON_VALIDATOR src/main.cpp)
target_link_libraries(JSON_VALIDATOR PRIVATE nlohmann_json::nlohmann_json)
