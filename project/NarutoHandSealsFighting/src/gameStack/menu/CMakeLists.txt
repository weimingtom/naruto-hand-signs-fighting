########################
######## MENU ########## 
########################

ADD_LIBRARY(menuLib SHARED MenuElement.cxx MainMenu.cxx OptionsMenu.cxx)

INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/gameStack")
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/gameStack/menu")