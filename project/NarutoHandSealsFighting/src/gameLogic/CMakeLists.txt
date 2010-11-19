#######################
##### Game Logic ######
#######################

ADD_LIBRARY(gameLogic SHARED SealsMap.cxx MoveSet.cxx MovesFactory.cxx SealsFactory.cxx
 Move.cxx HandSeal.cxx)

ADD_DEPENDENCIES(logicGame SealsSettings.h)
ADD_DEPENDENCIES(logicGame MovesSettings.h)

