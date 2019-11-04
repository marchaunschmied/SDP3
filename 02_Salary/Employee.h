///////////////////////////////////////////////////////////////////////////
// Workfile :		Employee.h
// Author :			Markus Riegler
// Date :			31.10.2019
// Description :	Header of class Employee
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
#include "Object.h"

//Enum for Employee spezifikation
enum class TWorker {CommissionWorker, PieceWorker, HourlyWorker, Boss};

class Employee: public Object
{
public:

	~Employee() = default;

	//Setter & Getter
	void SetName(std::string const& name);
	void SetSchortName(std::string const& sname);

	std::string GetSname() {
		return mShortName;
	}
	
	std::string GetInsuranceNr() const;
	size_t GetEntryYear() const;

	virtual double GetSalary() const = 0;
	TWorker GetType() const;

	void Print(std::ostream& ost);

protected:
	//Template Method
	virtual void PrintSalary(std::ostream& ost) const = 0;

	//No instance of Employee
	Employee(std::string const& firstname, std::string const& name,
		     std::string const& shortname, std::string const& insurance,
		     size_t const& entryyear, TWorker const worker);



private:
	std::string	mFirstName;
	std::string	mName;
	std::string	mShortName;
	std::string	mInsuranceNr;
	size_t		mEntryYear;
	TWorker		mWorker;

	//Helping Functions
	bool CheckInsuranceNr(std::string const& iNr) const;
	void PrintType(std::ostream& ost) const;
	
};

std::ostream& Currency(std::ostream& ost);


#endif // !EMPLOYEE_H

