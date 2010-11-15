##########################################
# Hello World example cmakelists file
#!!! Remember !!! 
# cmake is NOT case-sensitive
##########################################

########################
### ENGINE PROTOTYPE ### 
#### CMakeLists.txt ####
########################

cmake_minimum_required(VERSION 2.6)
PROJECT( enginePrototype_proj )
FIND_PACKAGE( OpenCV REQUIRED )
ADD_EXECUTABLE( enginePrototype mainEngine.cxx)
TARGET_LINK_LIBRARIES( enginePrototype ${OpenCV_LIBS} engLib sobel laplacian histo canny)
ADD_DEPENDENCIES(enginePrototype EngineModule.h)

ADD_DEPENDENCIES(enginePrototype engLib)
ADD_LIBRARY(engLib SHARED RecognitionEngine.h RecognitionEngine.cxx engineModules/EngineModule.h 
Move.h)

ADD_DEPENDENCIES(enginePrototype sobel)
ADD_LIBRARY(sobel SHARED engineModules/SobelEM.h engineModules/SobelEM.cxx)
ADD_DEPENDENCIES(sobel engineModules/EngineModule.h)

ADD_DEPENDENCIES(enginePrototype laplacian)
ADD_LIBRARY(laplacian SHARED engineModules/LaplacianEM.h engineModules/LaplacianEM.cxx)
ADD_DEPENDENCIES(laplacian engineModules/EngineModule.h)

ADD_DEPENDENCIES(enginePrototype histo)
ADD_LIBRARY(histo SHARED engineModules/HistogramEM.h engineModules/HistogramEM.cxx)
ADD_DEPENDENCIES(histo engineModules/EngineModule.h)

ADD_DEPENDENCIES(enginePrototype canny)
ADD_LIBRARY(canny SHARED engineModules/CannyEM.h engineModules/CannyEM.cxx)
ADD_DEPENDENCIES(canny engineModules/EngineModule.h)

#ADD_DEPENDENCIES(enginePrototype fourier)
#ADD_LIBRARY(fourier SHARED FourierEM.h FourierEM.cxx)
#ADD_DEPENDENCIES(fourier engineModules/EngineModule.h)

#new library
#remember to add the <"mylib"> name in TARGET_LINK_LIBRARIES
#ADD_DEPENDENCIES(contours  <"mylib">)
#ADD_LIBRARY(<"mylib"> SHARED <"mylib">.h <"mylib">.cxx)