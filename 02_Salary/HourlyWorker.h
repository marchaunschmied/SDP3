///////////////////////////////////////////////////////////////////////////
// Workfile :		HourlyWorker.h
// Author :			Markus Riegler
// Date :			31.10.2019
// Description :	Header of class HourlyWorker
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef HOURLYWORKER_H
#define HOURLYWORKER_H

#include "Employee.h"

class HourlyWorker : public Employee
{
public:
	HourlyWorker(std::string const& firstname, std::string const& name,
				 std::string const& shortname, std::string const& insurance,
				 size_t const& entryyear);
	//default DTor is enough
	~HourlyWorker() = default;

	//Setter & Getter
	double GetSalary() const override;

	void SetWage(double wage);
	void SetHours(double hours);

protected:
	//Template Method
	void PrintSalary(std::ostream& ost) const override;

private:
	double mWagepH;
	double mHours;

};
#endif // !HOURLYWORKER_H

