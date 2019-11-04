///////////////////////////////////////////////////////////////////////////
// Workfile :		ICompany.h
// Author :			Marc Haunschmied
// Date :			02.11.2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////
#ifndef ICOMPANY_H
#define ICOMPANY_H

#include <iostream>
#include "Object.h"
#include "Employee.h" //is needed for TWorker

class ICompany{
public:

	virtual ~ICompany() = default;

	virtual size_t GetNrEmployees() const = 0;
	virtual size_t CountWorkerType(TWorker const& worker) const = 0;
	virtual size_t PiecesProduced() const = 0;
	virtual size_t PiecesSold() const = 0;
	virtual size_t AmountBornBefore(size_t const& year) const = 0;
	virtual Employee* FindByShortName(std::string const& sname) const = 0;
	virtual Employee* LongestEmployee() const = 0;
	virtual void PrintAll(std::ostream& ost) const  = 0;
};

#endif;
