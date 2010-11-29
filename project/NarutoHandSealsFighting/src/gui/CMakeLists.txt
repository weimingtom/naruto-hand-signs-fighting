########################################
################ GUI ###################
########################################

ADD_LIBRARY(gui SHARED AbstractFactory.cxx MenuWindow.cxx TrainingWindow.cxx ButtonMenu.cxx
ThumbnailImage.cxx AbstractGUIObject.cxx myButtonListener.cxx)

ADD_DEPENDENCIES(gui AbstractGUIObject.h)

FILE(COPY ${PROJECT_SOURCE_DIR}/gui/guichan-0.8.2/examples/fixedfont.bmp
	DESTINATION ${PROJECT_BINARY_DIR}/gui)

ADD_EXECUTABLE(guiTest guiTest.cxx)
TARGET_LINK_LIBRARIES(guiTest gui guichan guichan_sdl)