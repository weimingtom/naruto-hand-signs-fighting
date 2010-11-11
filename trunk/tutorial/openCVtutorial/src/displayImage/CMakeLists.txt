##########################################
# Hello World example cmakelists file
#!!! Remember !!! 
# cmake is NOT case-sensitive
##########################################

cmake_minimum_required(VERSION 2.6)
PROJECT( displayImage_proj )
FIND_PACKAGE( OpenCV REQUIRED )
ADD_EXECUTABLE( displayImage displayImage.cpp )
TARGET_LINK_LIBRARIES( displayImage ${OpenCV_LIBS} )