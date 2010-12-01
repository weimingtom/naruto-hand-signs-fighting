########################################
################ GUI ###################
########################################

ADD_LIBRARY(gui SHARED AbstractFactory.cxx MenuWindow.cxx TrainingWindow.cxx 
  myButtonListener.cxx AbstractEventListener.cxx EventToKeyPressConverter.cxx 
  MovesListWindow.cxx OptionsWindow.cxx MovesListListener.cxx MovesListBoxListener.cxx)

INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/gui")
INCLUDE_DIRECTORIES("${PROJECT_BINARY_BIR}/gui/guichan-0.8.2/include")
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/gui/guichan-0.8.2/include/guichan/sdl")

ADD_SUBDIRECTORY(guichan-0.8.2)

#ADD_DEPENDENCIES(gui AbstractGUIObject.h)
ADD_DEPENDENCIES(gui guichan guichan_sdl)

#FILE(COPY ${PROJECT_SOURCE_DIR}/gui/guichan-0.8.2/examples/fixedfont.bmp
#	DESTINATION ${PROJECT_BINARY_DIR}/gui)
	
FILE(COPY ${PROJECT_SOURCE_DIR}/gui/guichan-0.8.2/examples/rpgfont.bmp
	DESTINATION ${PROJECT_BINARY_DIR}/gui)

ADD_EXECUTABLE(guiTest guiTest.cxx)
TARGET_LINK_LIBRARIES(guiTest gui  guichan_sdl guichan gameLogic gameStack controllerLib 
	${OpenCV_LIBS} menuLib deb camLib)

