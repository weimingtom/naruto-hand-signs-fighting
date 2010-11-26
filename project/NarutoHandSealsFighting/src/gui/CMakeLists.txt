########################################
################# GUI ##################
########################################

ADD_SUBDIRECTORY(guichan-0.8.2)

#INCLUDE_DIRECTORIES(include "${PROJECT_SOURCE_DIR}/gui/guichan-0.8.2/include/guichan/sdl")
#INCLUDE_DIRECTORIES(include "${PROJECT_BINARY_DIR}/gui/guichan-0.8.2/include")

ADD_EXECUTABLE(guiTut boh.cxx)
TARGET_LINK_LIBRARIES(guiTut guichan guichan_sdl)
 
#INCLUDE(ExternalProject)
#ExternalProject_add (
#	guichanLib
#	PREFIX ${PROJECT_BINARY_DIR}/gui/guichan-0.8.2
#	SOURCE_DIR ${PROJECT_SOURCE_DIR}/gui/guichan-0.8.2
#	#CONFIGURE_COMMAND ./configure
#	BINARY_DIR ${PROJECT_BINARY_DIR}/gui/guichan-0.8.2
#	#BUILD_COMMAND make
#	INSTALL_DIR ${PROJECT_BINARY_DIR}/gui/guichan-0.8.2
#	INSTALL_COMMAND -DCMAKE_INSTALL_PREFIX make install
#)


