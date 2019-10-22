///////////////////////////////////////////////////////////////////////////
// Workfile :		LogBook.h
// Author :			Marc Haunschmied
// Date :			2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////
#ifndef LogBook_H
#define LogBook_H

#include <string>
#include <ostream>
#include <vector>
#include <ctime>

#include "Object.h"

struct TEntry {
	tm date; 
	size_t distance;
};



class LogBook: public Object {
private:
	std::vector<TEntry> mEntries;
public:
	bool AddEntry(std::string const& date, size_t const& distance);
	void PrintLog(std::ostream& ost) const;
	size_t SumDistance() const;

	~LogBook() {}
};


#endif








