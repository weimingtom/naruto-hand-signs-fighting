#######################
# Processing Functions #
#######################

ADD_LIBRARY(processingFunctions SHARED DifferentTempsAdder.cxx ChainAdder.cxx )

ADD_DEPENDENCIES(processingFunctions AbstractProcessingFunction.h)

