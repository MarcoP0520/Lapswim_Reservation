cmake_minimum_required(VERSION 3.29)
project(Lapswim_Reservation)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lapswim_Reservation lapSwim.cpp main.cpp waitList.cpp)
