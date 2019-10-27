///////////////////////////////////////////////////////////////////////////
// Workfile :		Entry.h
// Author :			Marc Haunschmied
// Date :			2019
// Description :	Represents a Entry in a LogBook. It consists of a date
//					represeneted by a string and a distance in kilometers
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef ENTRY_H
#define ENTRY_H
#include <string>
#include "Object.h"

class Entry : public Object{
private:
	std::string date;	//date format is "YYMMDD" (ISO)
	size_t distance;
public:

	Entry(std::string const& date ="", size_t const& distance=0) : date(date), distance(distance) {}
	~Entry() {};

	std::string GetDate() const;
	size_t GetDist() const;

	std::string GetYear() const;
	std::string GetMon() const ;
	std::string GetDay() const;

};

#endif
