########################################
################ GUI ###################
########################################

ADD_LIBRARY(gui SHARED AbstractFactory.cxx MenuWindow.cxx TrainingWindow.cxx ButtonMenu.cxx
ThumbnailImage.cxx AbstractGUIObject.cxx myButtonListener.cxx)

ADD_DEPENDENCIES(gui AbstractGUIObject.h)