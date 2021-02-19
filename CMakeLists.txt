cmake_minimum_required(VERSION 3.16)
project(ex4)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex4 Matrix.cpp Matrix.h Activation.h Activation.cpp Dense.cpp Dense.h MlpNetwork.cpp main.cpp)