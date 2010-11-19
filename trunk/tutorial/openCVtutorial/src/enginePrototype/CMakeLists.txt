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

#######################
##### Directories #####
#######################
# add the binary tree to the search path for include files
# so that we will find all *.h files
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}")
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/engineModules")

ADD_SUBDIRECTORY(engineModules)
#######################

#######################
##### Main Target #####
#######################
ADD_EXECUTABLE( enginePrototype mainEngine.cxx)
TARGET_LINK_LIBRARIES( enginePrototype ${OpenCV_LIBS} engine engineModules)
ADD_LIBRARY(engine SHARED RecognitionEngine.h RecognitionEngine.cxx engineModules/EngineModule.h 
Move.h)
#######################

#######################
#### Dependencies #####
#######################
ADD_DEPENDENCIES(enginePrototype EngineModule.h)
ADD_DEPENDENCIES(enginePrototype engine)
ADD_DEPENDENCIES(enginePrototype engineModules)
#######################
