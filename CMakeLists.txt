cmake_minimum_required(VERSION 3.27)
project(Address)

set(CMAKE_CXX_STANDARD 17)

add_executable(Address main.cpp
        Address.cpp
        Address.h
        Person.cpp
        Person.h
        Employee.cpp
        Employee.h
        Point.cpp
        Point.h
        Rectangle.cpp
        Rectangle.h)
