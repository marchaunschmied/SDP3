///////////////////////////////////////////////////////////////////////////
// Workfile :		LogBook.cpp
// Author :			Marc Haunschmied
// Date :			2019
// Description :	Kilometres driven on each day are saved in this LogBook
// Revision :
///////////////////////////////////////////////////////////////////////////
#include <iomanip>
#include <algorithm>
#include <numeric>
#include "LogBook.h"
#include "Entry.h"


//Adds an Entry to the LogBook
bool LogBook::AddEntry(std::string const& date, size_t const& distance) {

	//check date format (YYMMDD) for example 191028
	if (date.length() == 6 && std::all_of(date.begin(), date.end(), ::isdigit)) {

		//find inserting Position to maintain sorting
		auto insertPos = std::lower_bound(mEntries.cbegin(), mEntries.cend(), Entry{ date, 0 }, [](Entry const & e1, Entry const & e2) {
				return e1.GetDate() < e2.GetDate();
			});

		try {
			mEntries.insert(insertPos, Entry{ date,distance });
		}
		catch (std::bad_alloc & ex) {
			throw std::string{ "error when trying to insert in vector" };
		}
		return true;
	}
	else {
		return false;
	}
}


//manipulator to format a date with padding zeros 
std::ostream& format_date(std::ostream& ost) {
	if (ost.good()) {
		ost << std::setw(2) << std::setfill('0');
	}
	return ost;
}

//prints all logbook entries with formatted date and distance
void LogBook::PrintLog(std::ostream& ost) const {
	if (ost.good()) {
		for (Entry entry : mEntries) {
			ost << format_date <<  entry.GetDay() << "." << format_date << entry.GetMon() << "."  << format_date << entry.GetYear() << ": " << entry.GetDist() << " km" << std::endl;
		}
	}
}

//calculates the sum of all logbook entries
size_t LogBook::SumDistance() const {
	return std::accumulate(mEntries.cbegin(), mEntries.cend(), 0, [](int sum, Entry const & entry2) {
		return sum + entry2.GetDist();
	});
}
