#ifndef REVOLUTION_SENSOR_H
#define REVOLUTION_SENSOR_H

#include <fstream>
#include "Object.h"



class RevolutionSensor : Object {
public:
	size_t GetRevolutions();
private:
	std::ifstream stream;

	//Help functions 
	void OpenFile();
};

#endif