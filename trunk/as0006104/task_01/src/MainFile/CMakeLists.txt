cmake_minimum_required (VERSION 3.0.0)
 
project(Main)
 
set(SOURCE_FILE "main.cpp")
 
add_executable (Main ${SOURCE_FILE})
 
# Connecting the library, specify where to get the header files
include_directories("../models")
# And also we specify dependence on static library
target_link_libraries(Main LinearModel NonlinearModel)