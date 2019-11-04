///////////////////////////////////////////////////////////////////////////
// Workfile :		Boss.h
// Author :			Markus Riegler
// Date :			31.10.2019
// Description :	Header of class Boss
// Revision :		1
///////////////////////////////////////////////////////////////////////////
#ifndef BOSS_H
#define BOSS_H

#include "Employee.h"

class Boss : public Employee
{
public:
	//CTor
	Boss(std::string const& firstname, std::string const& name,
		 std::string const& shortname, std::string const& insurance,
		 size_t const& entryyear);
	//default DTor is enough
	~Boss() = default;

	//Setter & Getter
	double GetSalary() const override;
	void SetSalary(double salary);

protected:
	//Template Method
	void PrintSalary(std::ostream& ost) const override;

private:
	double mSalary;

};
#endif // !BOSS_H
