/*
 ******************************************************
 * NAME:
 * HandSeal.h
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 19, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef HANDSEAL_H_
#define HANDSEAL_H_

#include <string>
#include <opencv/cv.h>

using namespace std;

class HandSeal{
	string month, japaneseName, name;
	int ID;
	IplImage* templateImage;
	IplImage* thumbnailImage;
public:
	HandSeal(string m, string jap, string nameKey, int i);
	HandSeal(const char* m, const char* jap, const char* nameKey, int i);

	void setImages(const char* templateImagePath, const char* thumbnailsImagePath);

    int getID() const
    {
        return ID;
    }

    String getMonth() const
    {
        return month;
    }

    IplImage *getTemplateImage() const
    {
        return templateImage;
    }

    IplImage *getThumbnailImage() const
    {
        return thumbnailImage;
    }

    void setTemplateImage(IplImage *templateImage)
    {
        this->templateImage = templateImage;
    }

};


#endif /* HANDSEAL_H_ */