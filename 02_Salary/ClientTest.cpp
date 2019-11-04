///////////////////////////////////////////////////////////////////////////
// Workfile :		ClientTest.cpp
// Author :			Marc Haunschmied
// Date :			2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////



#include <iostream>

#include "ClientTest.h"
#include "Company.h"
#include "Employee.h"
#include "Boss.h"
#include "CommissionWorker.h"
#include "HourlyWorker.h"
#include "PieceWorker.h"

void ClientTest::Test(ICompany* comp) {
	
	comp->PrintAll(std::cout);

	std::cout << "Nr Employees:       " << comp->GetNrEmployees() << std::endl;
	std::cout << "Bosses:             " << comp->CountWorkerType(TWorker::Boss) << std::endl;
	std::cout << "CommissionWorkers:  " << comp->CountWorkerType(TWorker::CommissionWorker) << std::endl;
	std::cout << "PieceWorkers:       " << comp->CountWorkerType(TWorker::PieceWorker) << std::endl;
	std::cout << "HourlyWorkers:      " << comp->CountWorkerType(TWorker::HourlyWorker) << std::endl;
	std::cout << "Pieces Produced:    " << comp->PiecesProduced() << std::endl;
	std::cout << "Pieces Sold:        " << comp->PiecesSold() << std::endl;
	std::cout << "Born Before 1970:   " << comp->AmountBornBefore(70) << std::endl;
	std::cout << "Longest Employee:   ";
	Employee* longEmp = comp->LongestEmployee();
	if (longEmp != nullptr) {
		std::cout << longEmp->GetSname() << std::endl;
	}
	else {
		std::cout << std::endl;
	}
	std::cout << "'rie' is employee:  " << std::boolalpha << (comp->FindByShortName("rie") != nullptr) << std::endl;
}