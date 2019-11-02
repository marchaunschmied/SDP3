///////////////////////////////////////////////////////////////////////////
// Workfile :		Company.cpp
// Author :			Marc Haunschmied
// Date :			02.11.2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////

#include "Company.h"

bool Company::AddEmployee(Employee* const& emp) {
	return true;
}
bool Company::DeleteEmployee(std::string const& sname) {
	return false;
}
size_t Company::GetNrEmployees() const {
	return 0;
}
size_t Company::CountWorkerType(TWorker const& worker) const {
	return 0;
}
size_t Company::PiecesProduced() const {
	return 0;
}
size_t Company::PiecesSold() const  {
	return 0;
}
size_t Company::AmountBornBefore(size_t const& year) const {
	return 0;
}
Employee* Company::FindByShortName(std::string const& sname) const {
	return nullptr;
}
Employee* Company::LongesEmployee() const {
	return nullptr;
}
void Company::PrintAll(std::ostream& ost) const {

}

