#!/bin/bash

TARGETS="acquisitionSection CMakeFiles gameLogic gameStack gui recognitionEngine templatesCreationSection cmake_install.cmake CMakeCache.txt CPackConfig.cmake CPackSourceConfig.cmake libdeb.a Makefile Moves.xml rpgfont.bmp"

#rm -r $TARGETS
for t in  $TARGETS 
	do
#		echo "$t"
		rm -r $t
	done
