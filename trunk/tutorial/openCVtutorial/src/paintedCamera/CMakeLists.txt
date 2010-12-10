##########################################
#!!! Remember !!! 
# cmake is NOT case-sensitive
##########################################

#######################
### Painted CAMERA TUTORIAL ### 
### CMakeLists.txt ####
#######################
#is the application of an additional image to the input from a camera

cmake_minimum_required(VERSION 2.6)
PROJECT( cameraTutorial_proj )
FIND_PACKAGE( OpenCV REQUIRED )
ADD_EXECUTABLE( paintedCamera mainPaintedCamera.cxx)
TARGET_LINK_LIBRARIES( paintedCamera ${OpenCV_LIBS} camLib)

ADD_DEPENDENCIES(paintedCamera camLib)
ADD_LIBRARY(camLib SHARED Camera.h Camera.cxx)
