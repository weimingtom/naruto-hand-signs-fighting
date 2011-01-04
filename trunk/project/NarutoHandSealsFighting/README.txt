#########################################################
############## Naruto Hand Seals Fighting ###############
######################## NHSF ###########################
####################### Project #########################
#########################################################

author: Michele Tamburini
mail: miketambu.at.gmail.com
University of Bologna

A revolutionary application that enables you to use your
bare hands in order to perform all the different seals 
of the Ninjutsu, exactly in the same way as your 
favorite heros do!

This is a source package.

#########################################################
1. REQUIREMENTS  ########################################
#########################################################

###  Hardware ###
 1. Webcam 
 	(integrated or external)
 	
### Software ###
 1. Operative System: Linux or Debian based
 	(tested on Linux Ubuntu 9.10)
 	
 2. Required Libraries & Software:
 	CMake, OpenCV, SDL, SDL_Image, Guichan
 	(please look the following for some hints
 	for the libraries retrieval)

You can use the standard package manager of your 
distribution (such as aptidue or apt-get) in order to 
retrieve the needed libraries or any other different 
way. Here's some package names that can help you in 
your search:
	CMake: 	cmake cmake-data
	 
	OpenCV: libcv1 libhighgui1 libcvaux1 libcv-dev libcvaux-dev libcvhighgui-dev
			
	SDL: libsdl1.2debian libsdl1.2debian-all libsdl1.2-dev libsdl-image1.2 libsdl-image1.2-dev
		 
	Guichan: libguichan-sdl libguichan-dev libguichan-0.8.1
	   (or you can just compile and install the 
	   current version provided by this package,
	   you can find it in
	   			./src/gui/guichan-0.8.2 
	   then $cmake . 
	   		$make 
	   		$make install
	   	) 

Alternatively you can just retrieve the source codes from
the official sites:

CMake: http://www.cmake.org/cmake/resources/software.html

OpenCV: http://sourceforge.net/projects/opencvlibrary/

SDL: http://www.libsdl.org/download-1.2.php

SDL_Image: http://www.libsdl.org/projects/SDL_image/

Guichan: 
http://guichan.sourceforge.net/wiki/index.php/Main_Page

#########################################################
2. INSTALLATION  ########################################
#########################################################
Once you get the necessary packages you have to change 
the directory and position into bin
			$cd bin
the type:
			$cmake ../src/
			$make

If no errors occur you are then ready to play. 

#########################################################
3. PLAYING  #############################################
#########################################################
Once you compiled the source code,
you can run the game by move into the bin directory
and launch the main program: runNHSF
			$./runNHSF 

#########################################################
4. CLEANING  ############################################
#########################################################
You can use the dist-Clean.sh script that you find in 
the bin directory in order to clean all the generated
files. It doesn't require any parameter.
			$cd bin
			$./dist-Clean.sh

!!!Warning!!!
It doesn't delete the templates and thumbnails image
directories (but generally you haven't to do it...)

#########################################################
5. TEMPLATE CREATION  ###################################
#########################################################
The current package is just provided by all the required
template images. Anyway if something strange happened
you can recreate them by:
			$cd src/templatesCreationSection
			$./templateCreator.sh

Look: in this way you can create you own templates!! ;)
The only thing to do is to rebuild the images of the
'sourceRawImages' directory, then re-run the above
script. I suggest to clean the images from the 
background before do so.
			
#########################################################
THANKS FOR DOWNLOADING AND TRYING IT!! =)  ##############
#########################################################
