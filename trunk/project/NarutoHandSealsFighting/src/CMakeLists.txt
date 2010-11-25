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
############### SDL CHECK ##############
########################################
IF (NOT SDL_FOUND)
	MESSAGE(FATAL_ERROR "SDL not found!")
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
TARGET_LINK_LIBRARIES( runNHSF ${OpenCV_LIBS} recognitionEngine gameLogic 
gameStack menuLib controllerLib)

#######################################

#######################################
############ Directories ##############
#######################################
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/recognitionEngine")
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/gameLogic")
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/templatesCreatoionSection")
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/gameStack")
INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIR})

#INCLUDE(${CMAKE_ROOT}/Modules/FindSDL.cmake)


ADD_SUBDIRECTORY(recognitionEngine)
ADD_SUBDIRECTORY(gameLogic)
ADD_SUBDIRECTORY(templatesCreationSection)
ADD_SUBDIRECTORY(gameStack)

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
