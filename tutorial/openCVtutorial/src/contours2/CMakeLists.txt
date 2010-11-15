##########################################
# Hello World example cmakelists file
#!!! Remember !!! 
# cmake is NOT case-sensitive
##########################################

cmake_minimum_required(VERSION 2.6)
PROJECT( contours2_proj )
FIND_PACKAGE( OpenCV REQUIRED )
ADD_EXECUTABLE( contours2 contours2Main.cxx)
TARGET_LINK_LIBRARIES( contours2 ${OpenCV_LIBS})
