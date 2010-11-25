########################
###### GAME STACK ###### 
########################

FIND_PACKAGE( OpenCV REQUIRED )
FIND_PACKAGE( SDL REQUIRED ) #<- how is it wrote???

ADD_LIBRARY(gameStack SHARED GameMachine.cxx FactoryGameMachine.cxx)

########################
##### directories ######
######################## 
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/gameStack")
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/gameStack/menu")
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/gameStack/controller")

ADD_DEPENDENCIES(gameStack GameElement.h)


ADD_SUBDIRECTORY(menu)
ADD_SUBDIRECTORY(controller)

########################
### executable test ####
########################
ADD_EXECUTABLE(gameStackTest gameStackTest.cxx)
TARGET_LINK_LIBRARIES(gameStackTest ${OpenCV_LIBS} gameStack menuLib controllerLib)
