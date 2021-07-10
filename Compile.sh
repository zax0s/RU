#!/bin/bash
g++ toolkits/PositrigoRU-ImageProcessing.cc src/ImageSpace.cc src/ImageProcessingManager.cc src/vImageProcess.cc src/iImageProcessErode.cc  -o PositrigoRU-ImageProcessing
g++ PositrigoRU.cc -o PositrigoRU

