##########################################
# Hello World example cmakelists file
#!!! Remember !!! 
# cmake is NOT case-sensitive
##########################################

cmake_minimum_required(VERSION 2.6)
PROJECT( imageTutorial_proj )
FIND_PACKAGE( OpenCV REQUIRED )
ADD_EXECUTABLE( contours contours.cxx)
TARGET_LINK_LIBRARIES( contours ${OpenCV_LIBS} histLib)

#new library
#remember to add the <"mylib"> name in TARGET_LINK_LIBRARIES
#ADD_DEPENDENCIES(contours  <"mylib">)
#ADD_LIBRARY(<"mylib"> SHARED <"mylib">.h <"mylib">.cxx)

ADD_DEPENDENCIES(contours histLib)
ADD_LIBRARY(histLib SHARED Histogram.h Histogram.cxx)
