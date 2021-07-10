cmake_minimum_required(VERSION 3.16)
project(PositrigoRU)

set(CMAKE_CXX_STANDARD 11)
# Defining a list of option
option( PositrigoRU-DEBUG "Enable many additional outputs for verification in development" NO )

add_executable(PositrigoRU PositrigoRU.cc)
add_executable(PositrigoRU-ImageProcessing toolkits/PositrigoRU-ImageProcessing.cc)
add_executable(PositrigoRUPositrigoRU.cc include/ImageSpace.hh src/ImageSpace.cc)
add_executable(PositrigoRU-ImageProcessing.cc include/ImageSpace.hh src/ImageSpace.cc)