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
	string month;
	string japaneseName;
	string name;
	int ID;
	string templateImagePath;
	string thumbnailImagePath;
	IplImage* templateImage;
	IplImage* thumbnailImage;
public:
	HandSeal(string m, string jap, string nameKey, int i);
	HandSeal(const char* m, const char* jap, const char* nameKey, int i);

	void setImages(const char* templateImagePath, const char* thumbnailsImagePath);

    string getTemplateImagePath() const
    {
        return templateImagePath;
    }

    string getThumbnailImagePath() const
    {
        return thumbnailImagePath;
    }

    void setTemplateImagePath(string templateImagePath)
    {
        this->templateImagePath = templateImagePath;
    }

    string getJapaneseName() const
    {
        return japaneseName;
    }

    string getName() const
    {
        return name;
    }

    void setName(string name)
    {
        this->name = name;
    }

    int getID() const
    {
        return ID;
    }

    string getMonth() const
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
