########################
## RECOGNITION ENGINE ## 
#### CMakeLists.txt ####
########################

cmake_minimum_required(VERSION 2.6)
PROJECT( recognitionEngine_Project )
FIND_PACKAGE( OpenCV REQUIRED )

#######################
##### Directories #####
#######################
# add the binary tree to the search path for include files
# so that we will find all *.h files
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}")
INCLUDE_DIRECTORIES("${PROJECT_SOURCE_DIR}/engineModules")
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/gameLogic")

ADD_SUBDIRECTORY(engineModules)
#######################

#######################
### Engine Target #####
#######################
ADD_EXECUTABLE( runRecognitionEngine mainEngine.cxx)
TARGET_LINK_LIBRARIES( runRecognitionEngine ${OpenCV_LIBS} recognitionEngine engineModules gameLogic)
ADD_LIBRARY(recognitionEngine SHARED  RecognitionEngine.h RecognitionEngine.cxx 
engineModules/EngineModule.h ../gameLogic/Move.h)

# add the command to generate the source code
#ADD_CUSTOM_COMMAND (
#  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/re.h
#  COMMAND runRecognitionEngine ${CMAKE_CURRENT_BINARY_DIR}/re.h
#  DEPENDS runRecognitionEngine
#  )
#######################

#######################
#### Dependencies #####
#######################
ADD_DEPENDENCIES(recognitionEngine EngineModule.h)
ADD_DEPENDENCIES(recognitionEngine engineModules)
#######################
