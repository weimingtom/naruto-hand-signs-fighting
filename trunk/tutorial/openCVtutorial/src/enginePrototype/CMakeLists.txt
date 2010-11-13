##########################################
# Hello World example cmakelists file
#!!! Remember !!! 
# cmake is NOT case-sensitive
##########################################

########################
### ENGINE PROTOTYPE ### 
#### CMakeLists.txt ####
########################

cmake_minimum_required(VERSION 2.6)
PROJECT( enginePrototype_proj )
FIND_PACKAGE( OpenCV REQUIRED )
ADD_EXECUTABLE( enginePrototype mainEngine.cxx)
TARGET_LINK_LIBRARIES( enginePrototype ${OpenCV_LIBS} engLib sobel)
ADD_DEPENDENCIES(enginePrototype EngineModule.h)

ADD_DEPENDENCIES(enginePrototype engLib)
ADD_LIBRARY(engLib SHARED RecognitionEngine.h RecognitionEngine.cxx EngineModule.h Move.h)

ADD_DEPENDENCIES(enginePrototype sobel)
ADD_LIBRARY(sobel SHARED SobelEM.h SobelEM.cxx)
ADD_DEPENDENCIES(sobel EngineModule.h)

#new library
#remember to add the <"mylib"> name in TARGET_LINK_LIBRARIES
#ADD_DEPENDENCIES(contours  <"mylib">)
#ADD_LIBRARY(<"mylib"> SHARED <"mylib">.h <"mylib">.cxx)