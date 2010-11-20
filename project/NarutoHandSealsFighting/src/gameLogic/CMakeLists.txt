#######################
##### Game Logic ######
#######################

ADD_LIBRARY(gameLogic SHARED SealsMap.cxx MovesSet.cxx MovesFactory.cxx SealsFactory.cxx 
SealsSettings.cxx Move.cxx HandSeal.cxx)

ADD_DEPENDENCIES(gameLogic SealsSettings.h)
ADD_DEPENDENCIES(gameLogic MovesSettings.h)
ADD_DEPENDENCIES(gameLogic SealsFactoryAbstract.h)

