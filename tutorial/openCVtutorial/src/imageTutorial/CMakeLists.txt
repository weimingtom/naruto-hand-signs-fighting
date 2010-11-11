##########################################
# Hello World example cmakelists file
#!!! Remember !!! 
# cmake is NOT case-sensitive
##########################################

cmake_minimum_required(VERSION 2.6)
PROJECT( imageTutorial_proj )
FIND_PACKAGE( OpenCV REQUIRED )
ADD_EXECUTABLE( imageTutorial imageTutorial.cxx)
TARGET_LINK_LIBRARIES( imageTutorial ${OpenCV_LIBS} myfourier)

#myFourier
ADD_DEPENDENCIES(imageTutorial myfourier)
ADD_LIBRARY(myfourier SHARED MyFourier.h MyFourier.cxx)
