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
FILE(COPY Moves.xml DESTINATION ${PROJECT_BINARY_DIR}/gameLogic)
FILE(COPY Moves.dtd DESTINATION ${PROJECT_BINARY_DIR}/gameLogic)

######################
###### XML_FILE ######
SET(XML_FILE ${PROJECT_BINARY_DIR}/gameLogic/Moves.xml)

configure_file (
  "${PROJECT_SOURCE_DIR}/gameLogic/MovesFactorySettings.h.in"
  "${PROJECT_BINARY_DIR}/gameLogic/MovesFactorySettings.h"
)

######################
# Test Executables ##
ADD_EXECUTABLE( sealsTest sealsTest.cxx)
TARGET_LINK_LIBRARIES( sealsTest ${OpenCV_LIBS} gameLogic)

ADD_EXECUTABLE( movesTest movesTest.cxx)
TARGET_LINK_LIBRARIES( movesTest ${OpenCV_LIBS} gameLogic)

#######################
# Linking Templates ###
#######################
#it links the directories of templates and thumbnail images
ADD_CUSTOM_COMMAND( TARGET sealsTest POST_BUILD 
	COMMAND ln -sf ${PROJECT_BINARY_DIR}/movesTemplates
	COMMAND ln -sf ${PROJECT_BINARY_DIR}/movesThumbnails
)
#######################