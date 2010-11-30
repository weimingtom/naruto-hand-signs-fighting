/*
 ******************************************************
 * NAME:
 * ThumbnailImage.h
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 28, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef THUMBNAILIMAGE_H_
#define THUMBNAILIMAGE_H_

#include "AbstractGUIObject.h"

class ThumbnailImage: public AbstractGUIObject {
public:
	ThumbnailImage(int x, int y);
	~ThumbnailImage();
};

#endif /* THUMBNAILIMAGE_H_ */
