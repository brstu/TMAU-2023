cmake_minimum_required(VERSION 3.5)
project(ConsoleApplication2)

set(SOURCES ConsoleApplication2.cpp Model.cpp Regulator.cpp Model.h Regulator.h Synchronizable.h)

add_executable(ConsoleApplication2 ${SOURCES})