cmake_minimum_required(VERSION 3.16)
project(PETRU)

set(CMAKE_CXX_STANDARD 11)
# Defining a list of option
option( PETRU-DEBUG "Enable many additional outputs for verification in development" NO )

add_executable(PETRU PETRU.cc)
add_executable(PETRU-ImageProcessing toolkits/PETRU-ImageProcessing.cc)
add_executable(PETRUPETRU.cc include/ImageSpace.hh src/ImageSpace.cc)
add_executable(PETRU-ImageProcessing.cc include/ImageSpace.hh src/ImageSpace.cc)
add_executable(PETRU-ImageProcessing.cc include/ImageProcessingManager.hh src/ImageProcessingManager.cc)
add_executable(PETRU-ImageProcessing.cc include/vImageProcess.hh src/vImageProcess.cc)
add_executable(PETRU-ImageProcessing.cc include/iImageProcessErode.hh src/iImageProcessErode.cc)