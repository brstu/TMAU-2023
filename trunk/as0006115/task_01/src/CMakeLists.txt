cmake_minimum_required(VERSION 3.0.0)
project(tempmodels VERSION 0.1.0 LANGUAGES C CXX)


add_executable(tempmodels main.cpp)

add_library(tempmodelslib STATIC
    lib/model.cpp
    lib/model.hpp
    )

target_link_libraries(tempmodels tempmodelslib)
