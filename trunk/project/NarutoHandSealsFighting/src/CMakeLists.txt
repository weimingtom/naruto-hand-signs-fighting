########################################
##### Naruto Hand Seals Fighting #######
############## NHSF ####################
############# Project ##################
########################################

# Creator: Michele Tamburini
# email: miketambu@gmail.com
# University of Bologna
# Starting date: nov 2010

CMAKE_MINIMUM_REQUIRED (VERSION 2.6)
project (NHSF)
FIND_PACKAGE( OpenCV REQUIRED )
FIND_PACKAGE( SDL REQUIRED)

########################################
############# OPENCV CHECK #############
########################################
#SET(OpenCV_FOUND false)
IF (NOT OpenCV_FOUND)
	MESSAGE(FATAL_ERROR "OpenCV library not found!
	You can visit the official site: 
	http://sourceforge.net/projects/opencvlibrary/ 
	to get a working version.
	Please be sure that all OpenCV tests are working properly in order to launch the current application." )
ENDIF (NOT OpenCV_FOUND)

########################################
############### SDL CHECK ##############
########################################
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
#########################################

# The version number.
set (NHSF_VERSION_MAJOR 1)
set (NHSF_VERSION_MINOR 0)

#######################################
############ Main Target ##############
#######################################
ADD_EXECUTABLE( runNHSF main-NHSF.cxx)
TARGET_LINK_LIBRARIES( runNHSF ${OpenCV_LIBS}
 recognitionEngine gameLogic 
gameStack menuLib controllerLib guichan guichan_sdl gui)

#######################################

#######################################
############ Directories ##############
#######################################

INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/recognitionEngine")
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/gameLogic")
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/templatesCreatoionSection")
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/gameStack")
INCLUDE_DIRECTORIES("${SDL_INCLUDE_DIR}")
#INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/gui")
#INCLUDE_DIRECTORIES("${PROJECT_BINARY_BIR}/gui/guichan-0.8.2/include")
#INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR}/gui/guichan-0.8.2/include/guichan/sdl)

ADD_SUBDIRECTORY(recognitionEngine)
ADD_SUBDIRECTORY(gameLogic)
ADD_SUBDIRECTORY(templatesCreationSection)
ADD_SUBDIRECTORY(gameStack)
ADD_SUBDIRECTORY(gui)

#######################################

#######################################
################ CPack ################
#######################################
# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${NHSF_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${NHSF_VERSION_MINOR}")
include (CPack)
#######################################
