cmake_minimum_required(VERSION 3.6)
project(000_LinkList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(000_LinkList ${SOURCE_FILES})