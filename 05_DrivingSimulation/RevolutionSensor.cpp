#include <iostream>
#include <string>
#include "RevolutionSensor.h"

size_t RevolutionSensor::GetRevolutions()
{
	if (!stream.is_open())
	{
		OpenFile();
	}

	if (!stream.eof())
	{
		std::string line = {0};
		std::getline(stream, line);
		if (line.empty())
		{
			std::cerr << "error read line" << std::endl;
		}
		line.erase(line.cend() - 1); // remove \n 
		return stoi(line);
	}
	else
	{
		return 0;
	}
}

void RevolutionSensor::OpenFile()
{
	stream.open("Revolutions.txt");
	if (!stream.is_open())
	{
		std::cerr << "error open Revolutions file" << std::endl;
	}
}
