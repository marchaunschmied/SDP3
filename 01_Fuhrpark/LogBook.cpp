///////////////////////////////////////////////////////////////////////////
// Workfile :		LogBook.cpp
// Author :			Marc Haunschmied
// Date :			2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////
#include <iomanip>
#include <algorithm>
#include <numeric>
#include "LogBook.h"


bool LogBook::AddEntry(std::string const& date, size_t const& distance) {
	tm time{ 0 };
	time.tm_year =	std::stoi(date.substr(0, 2),nullptr,0);
	time.tm_mon = std::stoi(date.substr(2, 2), nullptr, 0);
	time.tm_mday = std::stoi(date.substr(4, 2), nullptr, 0);
	mEntries.push_back(TEntry{ time, distance });
	return true;
}

std::ostream& format_date(std::ostream& ost) {
	if (ost.good()) {
		ost << std::setw(2) << std::setfill('0');
	}
	return ost;
}

void LogBook::PrintLog(std::ostream& ost) const {
	if (ost.good()) {
		for (TEntry entry : mEntries) {
			ost << format_date <<  entry.date.tm_mday << "." << format_date << entry.date.tm_mon << "."  << format_date << entry.date.tm_year << ": " << entry.distance << " km" << std::endl;
		}
	}
}

size_t LogBook::SumDistance() const {
	return std::accumulate(mEntries.cbegin(), mEntries.cend(), 0, [](int sum, TEntry const & entry2) {
		return sum + entry2.distance;
	});
}
