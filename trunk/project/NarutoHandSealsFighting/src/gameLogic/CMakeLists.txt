#######################
##### Game Logic ######
#######################

ADD_LIBRARY(gameLogic SHARED SealsMap.cxx MovesSet.cxx MovesFactory.cxx SealsFactory.cxx 
SealsSettings.cxx MovesSettings.cxx Move.cxx HandSeal.cxx)

ADD_DEPENDENCIES(gameLogic SealsSettings.h)
ADD_DEPENDENCIES(gameLogic MovesSettings.h)
ADD_DEPENDENCIES(gameLogic SealsFactoryAbstract.h)

ADD_EXECUTABLE( sealsTest sealsTest.cxx)
TARGET_LINK_LIBRARIES( sealsTest ${OpenCV_LIBS} gameLogic)

ADD_EXECUTABLE( movesTest movesTest.cxx)
TARGET_LINK_LIBRARIES( movesTest ${OpenCV_LIBS} gameLogic)
