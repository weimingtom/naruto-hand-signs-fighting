########################################
############ GUI TUTORIAL ##############
########################################

cmake_minimum_required(VERSION 2.8)
PROJECT(guichanGUITutorial)
FIND_PACKAGE( SDL REQUIRED)

############### SDL CHECK ##############
#SET(SDL_FOUND false)
IF (NOT SDL_FOUND)
	MESSAGE(FATAL_ERROR "SDL not found!
	You can visit the official site 
	http://www.libsdl.org/download-1.2.php
	to get a working version, or use the command 'aptitude install' or 'apt-get install' with the following packages:
	libsdl-dev libsdl1.2-all libsdl1.2-dev libsdl-image1.2 libsdl-image1.2-dev libsdl-ttf2.0-0 libsdl-ttf2.0-dev
	")
ENDIF (NOT SDL_FOUND)

INCLUDE_DIRECTORIES(include ${SDL_INCLUDE_DIR})
INCLUDE_DIRECTORIES(include ${SDL_IMAGE_INCLUDE_DIR})

LINK_LIBRARIES(
${SDL_LIBRARY}
${SDLIMAGE_LIBRARY} # if using SDL_image, obviously
SDLmain # Sadly not included in SDL_LIBRARY variable
)

FIND_PATH(GUICHAN_INCLUDE_DIR guichan.hpp 
 		        $ENV{GUICHANDIR}/include 
 		        REQUIRED 
  )  

FILE(COPY ${PROJECT_SOURCE_DIR}/guichan-0.8.2/examples/fixedfont.bmp
	DESTINATION ${PROJECT_BINARY_DIR})

ADD_SUBDIRECTORY(guichan-0.8.2)
ADD_SUBDIRECTORY(myGui)

ADD_EXECUTABLE(tutorialGui guiTutorial.cxx)

ADD_DEPENDENCIES(tutorialGui guichan)
TARGET_LINK_LIBRARIES(tutorialGui guichan guichan_sdl gui)

