#!/bin/bash
g++ toolkits/PetRU-ImageProcessing.cc src/ImageSpace.cc src/ImageProcessingManager.cc src/vImageProcess.cc src/iImageProcessErode.cc  -o PetRU-ImageProcessing
g++ PetRU.cc -o PetRU

