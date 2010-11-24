#######################
# Evaluation Functions #
#######################

ADD_LIBRARY(evaluationFunctions SHARED MulEvaluator.cxx)

ADD_DEPENDENCIES(evaluationFunctions EvaluatorFunctionTemplate.h)

INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/gameLogic")

