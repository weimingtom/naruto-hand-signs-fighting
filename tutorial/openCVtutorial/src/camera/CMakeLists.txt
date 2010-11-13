##########################################
# Hello World example cmakelists file
#!!! Remember !!! 
# cmake is NOT case-sensitive
##########################################

#######################
### CAMERA TUTORIAL ### 
### CMakeLists.txt ####
#######################

cmake_minimum_required(VERSION 2.6)
PROJECT( cameraTutorial_proj )
FIND_PACKAGE( OpenCV REQUIRED )
ADD_EXECUTABLE( camera cameraMain.cxx)
TARGET_LINK_LIBRARIES( camera ${OpenCV_LIBS} camLib)

#new library
#remember to add the <"mylib"> name in TARGET_LINK_LIBRARIES
#ADD_DEPENDENCIES(contours  <"mylib">)
#ADD_LIBRARY(<"mylib"> SHARED <"mylib">.h <"mylib">.cxx)

ADD_DEPENDENCIES(camera camLib)
ADD_LIBRARY(camLib SHARED Camera.h Camera.cxx)
