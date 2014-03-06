/*
 * File.h
 *
 *  Created on: 6 Mar 2014
 *      Author: Peter
 */

#ifndef FILE_H
#define FILE_H

#include "Grid.h"
#include <string>

using namespace std;

class File {
public:
	File();
	static Grid LoadDatafile(const char* strFileName);
	static void SaveDatafile(Grid& g,const char* strFileName);
};

#endif /* FILE_H */
