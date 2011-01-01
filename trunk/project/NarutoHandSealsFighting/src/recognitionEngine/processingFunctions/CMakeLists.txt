#######################
# Processing Functions #
#######################

ADD_LIBRARY(processingFunctions SHARED DifferentTempsAdder.cxx ChainAdder.cxx SimpleChain.cxx 
 SChainBGRemoval.cxx)

ADD_DEPENDENCIES(processingFunctions AbstractProcessingFunction.h)

