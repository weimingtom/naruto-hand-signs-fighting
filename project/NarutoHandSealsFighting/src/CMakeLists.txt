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

# The version number.
set (NHSF_VERSION_MAJOR 1)
set (NHSF_VERSION_MINOR 0)

#######################################
############ Main Target ##############
#######################################
ADD_EXECUTABLE( runNHSF main-NHSF.cxx)
TARGET_LINK_LIBRARIES( runNHSF ${OpenCV_LIBS} recognitionEngine )

#######################################

#######################################
############ Directories ##############
#######################################
INCLUDE_DIRECTORIES("${PROJECT_BINARY_DIR}/recognitionEngine")

ADD_SUBDIRECTORY(recognitionEngine)

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