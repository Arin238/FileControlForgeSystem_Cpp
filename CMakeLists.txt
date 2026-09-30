cmake_minimum_required(VERSION 3.31)
project(FileControlForgeSystem_Cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(FileControlForgeSystem_Cpp
        HashMap.cpp
        HashMap.h
        Heap.h
        Heap.cpp
        LRUCache.h)
