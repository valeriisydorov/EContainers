cmake_minimum_required(VERSION 3.27)
project(EContainer)

set(CMAKE_CXX_STANDARD 17)

add_executable(EContainer
        main.cpp
        EString/EStringTest.cpp
        EString/EString.cpp
        EList/EListTest.cpp
        EVector/EVectorTest.cpp
        ESet/ESetTest.cpp
)