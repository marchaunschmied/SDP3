///////////////////////////////////////////////////////////////////////////
// Workfile :		LogBook.h
// Author :			Marc Haunschmied
// Date :			2019
// Description :	Kilometres driven on each day are saved in this LogBook
// Revision :
///////////////////////////////////////////////////////////////////////////
#ifndef LogBook_H
#define LogBook_H

#include <string>
#include <ostream>
#include <vector>
#include <ctime>

#include "Object.h"
#include "Entry.h"

class LogBook: public Object {
private:
	std::vector<Entry> mEntries;
public:
	bool AddEntry(std::string const& date, size_t const& distance);
	void PrintLog(std::ostream& ost) const;
	size_t SumDistance() const;

	~LogBook() {}
};


#endif








