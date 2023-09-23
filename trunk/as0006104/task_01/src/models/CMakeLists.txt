cmake_minimum_required (VERSION 3.0.0)
 
project(Models)
 
add_library(LinearModel STATIC LinearModel.cpp LinearModel.hpp)
add_library(NonlinearModel STATIC NonlinearModel.cpp NonlinearModel.hpp)