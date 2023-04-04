cmake_minimum_required(VERSION 3.21)
project(queLab)

set(CMAKE_CXX_STANDARD 17)

add_executable(queLab main.cpp DynamicQueue.cpp DynamicQueuesTest.cpp DynamicQueue.h)
