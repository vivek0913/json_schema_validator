cmake_minimum_required(VERSION 3.10)
project(json_schema_validator)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(nlohmann_json REQUIRED)

add_executable(json_schema_validator
    src/main.cpp
    src/value.cpp
    src/json_loader.cpp
    src/print.cpp
    src/schema.cpp
    src/schema_loader.cpp
    src/validator.cpp
)

target_link_libraries(json_schema_validator PRIVATE nlohmann_json::nlohmann_json)
