///////////////////////////////////////////////////////////////////////////
// Workfile :		Entry.cpp
// Author :			Marc Haunschmied
// Date :			2019
// Description :	Represents a Entry in a LogBook. It consists of a date
//					represeneted by a string and a distance in kilometers
// Revision :
///////////////////////////////////////////////////////////////////////////

#include "Entry.h"

std::string Entry::GetDate() const {
	return date;
}

size_t Entry::GetDist() const {
	return distance;
}

std::string Entry::GetYear() const {
	return date.substr(0, 2);
}
std::string Entry::GetMon() const {
	return date.substr(2, 2);
}
std::string Entry::GetDay() const {
	return date.substr(4, 2);
}