cmake_minimum_required(VERSION 3.10)
project(ClockModule)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/Libs/Modules)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(..)

add_library(${PROJECT_NAME} SHARED
        Entrypoint.cpp
        Module.cpp Module.hpp
        ../../DataTypes.hpp
        ../../DataTypes.cpp ../../Data.cpp ../../Data.hpp)