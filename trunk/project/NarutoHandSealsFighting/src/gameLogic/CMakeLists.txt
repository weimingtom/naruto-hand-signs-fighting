#######################
##### Game Logic ######
#######################

ADD_SUBDIRECTORY(tinyxml)
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/tinyxml")

ADD_LIBRARY(gameLogic SHARED SealsMap.cxx MovesSet.cxx MovesFactory.cxx SealsFactory.cxx 
SealsSettings.cxx MovesSettings.cxx Move.cxx HandSeal.cxx)
TARGET_LINK_LIBRARIES(gameLogic tinyxml)

ADD_DEPENDENCIES(gameLogic SealsSettings.h)
ADD_DEPENDENCIES(gameLogic MovesSettings.h)
ADD_DEPENDENCIES(gameLogic SealsFactoryAbstract.h)
FILE(COPY MovesSeals.xml DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
FILE(COPY Moves.dtd DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

ADD_EXECUTABLE( sealsTest sealsTest.cxx)
TARGET_LINK_LIBRARIES( sealsTest ${OpenCV_LIBS} gameLogic)

ADD_EXECUTABLE( movesTest movesTest.cxx)
TARGET_LINK_LIBRARIES( movesTest ${OpenCV_LIBS} gameLogic)

