/*
 ******************************************************
 * NAME:
 * DebugPrint.h
 ******************************************************
 * DESCRIPTION:
 *
 ******************************************************
 *	Created on: Nov 24, 2010
 ******************************************************
 *  Author: Michele Tamburini
 *******************************************************
 *
 */

#ifndef DEBUGPRINT_H_
#define DEBUGPRINT_H_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void debugPrint(const char* s,...){
	char temp[256]; /* Holds our string */
	va_list ap;     /* Pointer to our list of elements */
	/* Parses The String For Variables */
	va_start( ap, s );
	/* Converts Symbols To Actual Numbers */
	vsprintf( temp, s, ap );
	va_end( ap );
	printf(temp);
	fflush(stdout);
}


#endif /* DEBUGPRINT_H_ */
