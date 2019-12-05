///////////////////////////////////////////////////////////////////////////
// Workfile :		RevolutionSensor.h
// Author :			Markus Riegler
// Date :			05-December-2019
// Description :	Header of class RevolutionSensor
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef REVOLUTION_SENSOR_H
#define REVOLUTION_SENSOR_H

#include <fstream>
#include "Object.h"



class RevolutionSensor : Object {
public:
	//Reads Revolutions from the File and returns it 
	size_t GetRevolutions();
	~RevolutionSensor();
private:
	//stream to the File
	std::ifstream stream;
	//Filename for Sensorvalues
	std::string const File = "Revolutions.txt";
	//Help functions 
	void OpenFile();
};

#endif