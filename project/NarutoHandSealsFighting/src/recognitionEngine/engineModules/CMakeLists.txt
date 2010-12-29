#######################
### Engine Modules ####
#######################

ADD_LIBRARY(engineModules SHARED SobelEM.cxx LaplacianEM.cxx HistogramEM.cxx CannyEM.cxx
ContoursFinderEM.cxx BlurEM.cxx ClosureEM.cxx BackgroundRemovalEM.cxx)

TARGET_LINK_LIBRARIES(engineModules camLib)

ADD_DEPENDENCIES(engineModules EngineModule.h)

