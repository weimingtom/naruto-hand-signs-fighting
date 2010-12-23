########################
## RECOGNITION ENGINE ## 
########################

cmake_minimum_required(VERSION 2.6)
#PROJECT( recognitionEngine_Project )
FIND_PACKAGE( OpenCV REQUIRED )

#######################
##### Directories #####
#######################
# add the binary tree to the search path for include files
# so that we will find all *.h files
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}")
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/engineModules")
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/engineStrategies")
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/evaluationFunctions")
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/gameLogic")
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/acquisitionSection")

ADD_SUBDIRECTORY(engineModules)
ADD_SUBDIRECTORY(evaluationFunctions)
ADD_SUBDIRECTORY(engineStrategies)
#######################

#######################
### Engine Target #####
#######################
ADD_EXECUTABLE( runRecognitionEngine mainEngine.cxx)
TARGET_LINK_LIBRARIES( runRecognitionEngine ${OpenCV_LIBS} recognitionEngine engineModules 
engineStrategies gameLogic evaluationFunctions deb )
ADD_LIBRARY(recognitionEngine SHARED  RecognitionEngine.h RecognitionEngine.cxx ImageProcessing.cxx
engineModules/EngineModule.h ../gameLogic/Move.h ModulesPool.cxx)

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
ADD_DEPENDENCIES(recognitionEngine engineStrategies)
#######################

#######################
##### Engine Test #####
#######################
ADD_EXECUTABLE( reTest reTest.cxx)
TARGET_LINK_LIBRARIES( reTest ${OpenCV_LIBS} recognitionEngine engineModules gameLogic 
evaluationFunctions deb engineStrategies camLib)

#######################
##### Moves File ######
#######################
#Moves file
FILE(COPY ${PROJECT_SOURCE_DIR}/gameLogic/Moves.xml 
	DESTINATION ${CMAKE_CURRENT_BINARY_DIR})