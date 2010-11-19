ADD_LIBRARY(MathFunctions mysqrt.cxx)

install (TARGETS MathFunctions DESTINATION bin)
install (FILES mysqrt.h DESTINATION include)