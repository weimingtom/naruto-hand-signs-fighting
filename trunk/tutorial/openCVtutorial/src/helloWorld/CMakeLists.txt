##########################################
# Hello World example cmakelists file
#!!! Remember !!! 
# cmake is NOT case-sensitive
##########################################

cmake_minimum_required(VERSION 2.6)
PROJECT( helloWorld_proj )
FIND_PACKAGE( OpenCV REQUIRED )
ADD_EXECUTABLE( helloWorld helloWorld.cxx )
TARGET_LINK_LIBRARIES( helloWorld ${OpenCV_LIBS} )