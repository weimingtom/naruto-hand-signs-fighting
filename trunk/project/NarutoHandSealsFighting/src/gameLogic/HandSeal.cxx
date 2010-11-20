/*
 * HandSeal.cxx
 *
 *  Created on: Nov 19, 2010
 *      Author: michele
 */

#include <iostream>
#include <opencv/highgui.h>
#include "HandSeal.h"

HandSeal::HandSeal(string m, string jap, string nameKey, int i){
	month = m;
	japaneseName = jap;
	name = nameKey;
	ID = i;
}

HandSeal::HandSeal(const char* m, const char* jap, const char* nameKey, int i){
	month = string(m);
	japaneseName = string(jap);
	name = string(nameKey);
	ID = i;
}

void HandSeal::setImages(const char* templImagePath, const char* thumbImagePath){
	try{
		templateImagePath = string(templImagePath);
		thumbnailImagePath = string(thumbImagePath);
		if(templImagePath != NULL)
			templateImage = cvLoadImage(templImagePath, CV_LOAD_IMAGE_GRAYSCALE);
		if(thumbImagePath != NULL)
			thumbnailImage = cvLoadImage(thumbImagePath, CV_LOAD_IMAGE_GRAYSCALE);

	}catch(cv::Exception e){
		cout<< e.err <<"\n";
	}
}
