########################
##### CONTROLLER ####### 
########################

ADD_LIBRARY(controllerLib SHARED AbstractController.cxx MainMenuController.cxx 
 MovesListController.cxx OptionsMenuController.cxx GeneralKeyboardController.cxx
 TrainingSectionController.cxx )
 
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/gameLogic")
