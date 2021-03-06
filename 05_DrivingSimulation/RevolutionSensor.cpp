///////////////////////////////////////////////////////////////////////////
// Workfile :		RevolutionSensor.cpp
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
	try {
		//first time -> called open File
		if (!stream.is_open())
		{
			OpenFile();
		}

		//EOF not yet reached
		if (!stream.eof())
		{
			//buffer for one line
			std::string line = { 0 };
			std::getline(stream, line);
			//didn't read anything
			if (line.empty())
			{
				std::cerr << ERROR_READ << std::endl;
				throw std::string{ ERROR_READ };
			}

			//convert ASCII string into integer
			try {
				return stoul(line);
			}
			catch (std::exception ex) {
				throw "invalid input in *.txt file: " + std::string{ ex.what() };
			}
		}
		//end of File already reached
		else
		{
			return 0;
		}
	}
	catch (std::string ex) {
		throw std::string{ ex };
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
		throw std::string{ ERROR_CLOSE };
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
		throw std::string{ ERROR_OPEN };
	}
}
