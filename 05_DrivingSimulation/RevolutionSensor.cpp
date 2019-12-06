///////////////////////////////////////////////////////////////////////////
// Workfile :		RevolutionSensor.h
// Author :			Markus Riegler
// Date :			05-December-2019
// Description :	Implementation of class RevolutionSensor
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include "RevolutionSensor.h"

///////////////////////////////////////////////////////////////////////////
//Error Constants
///////////////////////////////////////////////////////////////////////////
std::string const ERROR_READ = "error read line";
std::string const ERROR_OPEN = "error open Revolutions file";
std::string const ERROR_CLOSE = "error close Revolutions file";


///////////////////////////////////////////////////////////////////////////
// CTor sets file path
///////////////////////////////////////////////////////////////////////////
RevolutionSensor::RevolutionSensor(std::string const & path) : File(path){}

///////////////////////////////////////////////////////////////////////////
//Reads the Value from the file and returns it
///////////////////////////////////////////////////////////////////////////
size_t RevolutionSensor::GetRevolutions()
{
	//first time -> called open File
	if (!stream.is_open())
	{
		OpenFile();
	}

	//EOF not yet reached
	if (!stream.eof())
	{
		//buffer for one line
		std::string line = {0};
		std::getline(stream, line);
		//didn't read anything
		if (line.empty())
		{
			std::cerr << ERROR_READ << std::endl;
		}
		//line.erase(line.cend() - 1); // remove \n 
		//convert ASCII string into integer
		return stoi(line);
		
	}
	//end of File already reached
	else
	{
		return 0;
	}
}

///////////////////////////////////////////////////////////////////////////
//DTor closes File
///////////////////////////////////////////////////////////////////////////
RevolutionSensor::~RevolutionSensor()
{
	stream.close();
	if (stream.is_open())
	{
		std::cerr << ERROR_CLOSE << std::endl;
	}
}


///////////////////////////////////////////////////////////////////////////
//Opens the file with Sensor values
///////////////////////////////////////////////////////////////////////////
void RevolutionSensor::OpenFile()
{
	stream.open(File);
	//Opened?
	if (!stream.is_open())
	{
		std::cerr << ERROR_OPEN << std::endl;
	}
}
