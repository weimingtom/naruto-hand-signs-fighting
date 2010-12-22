##########################################
# Hello World example cmakelists file
#!!! Remember !!! 
# cmake is NOT case-sensitive
##########################################

cmake_minimum_required(VERSION 2.6)
PROJECT( contours2_proj )
FIND_PACKAGE( OpenCV REQUIRED )
ADD_EXECUTABLE( contoursCamera contours2Main.cxx)
TARGET_LINK_LIBRARIES( contoursCamera ${OpenCV_LIBS} camera histo)

ADD_LIBRARY(camera Camera.cxx)
ADD_LIBRARY(histo HistogramEM.cxx)
