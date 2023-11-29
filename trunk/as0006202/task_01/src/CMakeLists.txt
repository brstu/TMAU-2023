cmake_minimum_required(VERSION 2.8)
add_executable (tmau1_c_make "tmau1_c_mk.cpp" "tmau1_c_mk.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET tmau1_c_mk PROPERTY CXX_STANDARD 20)
endif()