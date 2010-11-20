/*
 * SealsSettings.h
 *
 *  Created on: Nov 19, 2010
 *      Author: michele
 */

#ifndef SEALSSETTINGS_H_
#define SEALSSETTINGS_H_

#include <string>

#define SEALS_NUMBER 12

using namespace std;

struct HandSealStruct{
	const char* name;
	const char* japaneseName;
	const char* month;
	const char* templatePath;
	const char* thumbnailPath;
};

extern HandSealStruct globSeals[];
extern const string TEMPLATE_PATH;


#endif /* SEALSSETTINGS_H_ */
