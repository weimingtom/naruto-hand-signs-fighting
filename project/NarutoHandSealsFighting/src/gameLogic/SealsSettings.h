/*
 * SealsSettings.h
 *
 *  Created on: Nov 19, 2010
 *      Author: michele
 */

#ifndef SEALSSETTINGS_H_
#define SEALSSETTINGS_H_

#define SEALS_NUMBER 12

struct Seals{
	const char* name;
	const char* japaneseName;
	const char* month;
	const char* templatePath;
	const char* thumbnailPath;
};

extern Seals globalSeals[];


#endif /* SEALSSETTINGS_H_ */
