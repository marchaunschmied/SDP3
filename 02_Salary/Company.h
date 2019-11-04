///////////////////////////////////////////////////////////////////////////
// Workfile :		Company.h
// Author :			Marc Haunschmied
// Date :			02.112019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////
#ifndef COMPANY_H
#define COMPANY_H

#include<list>
#include "ICompany.h"

class Company : public ICompany, public Object {

private:
	std::list<Employee*> mEmployees;

	std::string mName;
	std::string mLocation;

public:

	Company(std::string const& name, std::string const& location): mName(name), mLocation(location) {
	}

	bool AddEmployee(Employee* const& emp);
	Employee* DeleteEmployee(std::string const& sname);

	size_t GetNrEmployees() const;
	size_t CountWorkerType(TWorker const& worker) const;
	size_t PiecesProduced() const;
	size_t PiecesSold() const;
	size_t AmountBornBefore(size_t const& year) const;
	Employee* FindByShortName(std::string const& sname) const;
	Employee*LongestEmployee() const;
	void PrintAll(std::ostream& ost) const;
};

#endif

