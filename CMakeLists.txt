cmake_minimum_required(VERSION 3.15)
project(hw1)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_split test_split.cpp split.cpp
        ulliststr.cpp)
add_executable(test_ulliststr test_ulliststr.cpp ulliststr.cpp)
