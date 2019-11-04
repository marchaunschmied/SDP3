///////////////////////////////////////////////////////////////////////////
// Workfile :		Company.cpp
// Author :			Marc Haunschmied
// Date :			02.11.2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////


#include <numeric>		//for accumulate
#include "time.h"
#include "CommissionWorker.h"
#include "PieceWorker.h"
#include "Company.h"

//adds an existing employee to the company
bool Company::AddEmployee(Employee* const& emp) {
	if (emp != nullptr) {
		mEmployees.emplace_back(emp);
		return true;
	}
	return false;
}

//removes an employee from the company
//returns pointer to the removed employee
Employee* Company::DeleteEmployee(std::string const& sname) {

	Employee* emp = FindByShortName(sname);
	if (emp != nullptr) {
		mEmployees.remove(emp);
		return emp;
	}
	else {
		return nullptr;
	}
}

//returns amount of employees
size_t Company::GetNrEmployees() const {
	return mEmployees.size();
}

//counts how many specific worker types are in the company
size_t Company::CountWorkerType(TWorker const& worker) const {
	return std::count_if(mEmployees.cbegin(), mEmployees.cend(), [&worker](Employee * const & emp) {
		return emp->GetType() == worker;
		});
}

//counts the pieces produced by all PieceWorkers
size_t Company::PiecesProduced() const {
	size_t val =  std::accumulate(mEmployees.cbegin(), mEmployees.cend(), 0, [](size_t sum, Employee * const & emp) {
		if (emp->GetType() == TWorker::PieceWorker) {
			PieceWorker* p = dynamic_cast<PieceWorker*>(emp);
			return sum + p->GetPieces();
		}
		else {
			return sum;
		}
	});

	return val;
}

//counts the pieces sold by all CommissionWorkers
size_t Company::PiecesSold() const  {
	return std::accumulate(mEmployees.cbegin(), mEmployees.cend(), 0, [](size_t sum, Employee* const& emp) {
		if (emp->GetType() == TWorker::CommissionWorker) {
			CommissionWorker* c = dynamic_cast<CommissionWorker*>(emp);
			return sum + c->GetPieces();
		}
		else {
			return sum;
		}
		});
}

size_t Company::AmountBornBefore(size_t const& year) const {
	return std::count_if(mEmployees.cbegin(), mEmployees.cend(), [&year](Employee* const& emp) {
		size_t const yearPos = 8;
		size_t const yearLen = 2;
		//convert insurance nr to birthyear (10 digit number, the last 2 elements are the birth year)
		size_t empYear = std::stoi((emp->GetInsuranceNr().substr(yearPos,yearLen)),0);
		
		//calculate current year
		//this method only works for this century 
		time_t timer = time(0);
		tm ti;
		localtime_s(&ti, &timer);

		
		//tm_year returns years after 1900 --> 100 needs to get substracted
		int currentYear =  ti.tm_year - 100;
		int val = currentYear - empYear;
		if (val > 0) {
			return false;
		}
		
		return empYear < year;
		});
}

//returns pointer to employee if exists
Employee* Company::FindByShortName(std::string const& sname) const {
	auto it = std::find_if(mEmployees.cbegin(), mEmployees.cend(), [&sname](Employee* const& emp) {
		return sname == emp->GetSname();
		});
	if (it != mEmployees.end()) {
		return *it;
	}
	else {
		return nullptr;
	}
}

//returns the employee who is longest time in the company
Employee* Company::LongestEmployee() const {
	auto it = std::min_element(mEmployees.cbegin(), mEmployees.cend(), [](Employee * const & emp1, Employee * const & emp2) {
		return emp1->GetEntryYear() < emp2->GetEntryYear();
		});
	if (it != mEmployees.end()) {
		return *it;
	}
	else {
		return nullptr;
	}
}

//prints all employees
void Company::PrintAll(std::ostream& ost) const {
	if (ost.good()) {

		//print header
		ost << "****************************************" << std::endl;
		ost << mName << ", " << mLocation << std::endl;
		ost << "****************************************" << std::endl;

		for (Employee* emp : mEmployees) {
			emp->Print(ost);
			ost << std::endl;
		}
	}
}

