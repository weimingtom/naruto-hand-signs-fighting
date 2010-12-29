#######################
## Template Creator ###
#######################

ADD_EXECUTABLE( createTemplates templateCreatorLauncher.cxx)
TARGET_LINK_LIBRARIES( createTemplates ${OpenCV_LIBS} templateCreator recognitionEngine 
engineModules engineStrategies evaluationFunctions processingFunctions deb)

ADD_LIBRARY(templateCreator SHARED TemplateCreator.cxx)

OPTION(DEFAULT_DST_PATH "Destination path of the templates" "${PROJECT_BINARY_DIR}/movesTemplates")

ADD_DEPENDENCIES(createTemplates TemplateCreator.h)

configure_file (
  "${PROJECT_SOURCE_DIR}/templatesCreationSection/templateCreatorLauncher.h.in"
  "${PROJECT_BINARY_DIR}/templatesCreationSection/templateCreatorLauncher.h"
  )

INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/templatesCreationSection")
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/recognitionEngine")

FILE(COPY templateCreator.sh DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
FILE(COPY README.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
