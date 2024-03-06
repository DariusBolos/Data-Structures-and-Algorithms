cmake_minimum_required(VERSION 3.27)
project(adt_map)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(adt_map
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        Map.cpp
        Map.h
        MapIterator.cpp
        MapIterator.h
        ShortTest.cpp
        ShortTest.h)
