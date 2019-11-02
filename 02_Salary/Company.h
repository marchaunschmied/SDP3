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

class Company : public ICompany {

private:
	std::list<Employee*> mEmployees;

public:
	bool AddEmployee(Employee* const& emp);
	bool DeleteEmployee(std::string const& sname);

	size_t GetNrEmployees() const;
	size_t CountWorkerType(TWorker const& worker) const;
	size_t PiecesProduced() const;
	size_t PiecesSold() const;
	size_t AmountBornBefore(size_t const& year) const;
	Employee* FindByShortName(std::string const& sname) const;
	Employee*LongesEmployee() const;
	void PrintAll(std::ostream& ost) const;
};

#endif

