########################
##### CONTROLLER ####### 
########################

ADD_LIBRARY(controllerLib SHARED AbstractController.cxx MainMenuController.cxx 
OptionsMenuController.cxx)

#INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/gameStack")
#INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/gameStack/menu")