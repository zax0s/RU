cmake_minimum_required(VERSION 3.16)
project(PositrigoRU)

set(CMAKE_CXX_STANDARD 11)

add_executable(PositrigoRU PositrigoRU.cc)
add_executable(PositrigoRU-ImageProcessing toolkits/PositrigoRU-ImageProcessing.cc)