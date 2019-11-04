///////////////////////////////////////////////////////////////////////////
// Workfile :		main.cpp
// Author :			Marc Haunschmied
// Date :			2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "Company.h"

#include "Boss.h"
#include "CommissionWorker.h"
#include "Employee.h"
#include "HourlyWorker.h"
#include "PieceWorker.h"
#include "vld.h"

using namespace std;

int main() {

	Company comp("Fa. HSD", "Hagenberg");


	Boss *b = new Boss{ "Markus", "Riegler", "rie", "1234010196", 2010 };
	b->SetSalary(2500.0);
	

	CommissionWorker *c = new CommissionWorker{ "Marc", "Haunschmied", "hmm", "9999021191", 2009 };
	c->SetSalary(1750.0);
	c->SetPieces(250);
	c->SetRate(4.32);

	HourlyWorker* h = new HourlyWorker{ "Max", "Mustermann", "mam", "1234041101", 2017 };
	h->SetHours(187.5);
	h->SetWage(14.6);

	PieceWorker* p = new PieceWorker{ "Arnold", "Schwarzenegger", "sca", "4711300747", 1967 };
	p->SetPieces(332);
	p->SetRate(3.56);

	comp.AddEmployee(b);
	comp.AddEmployee(c);
	comp.AddEmployee(h);
	comp.AddEmployee(p);

	comp.PrintAll(cout);
	cout << boolalpha << comp.DeleteEmployee("hmm") << endl;
	comp.PrintAll(cout);

	cout << "Nr Employees:       " << comp.GetNrEmployees() << endl;
	cout << "Bosses:             " << comp.CountWorkerType(TWorker::Boss) << endl;
	cout << "CommissionWorkers:  " << comp.CountWorkerType(TWorker::CommissionWorker) << endl;
	cout << "PieceWorkers:       " << comp.CountWorkerType(TWorker::PieceWorker) << endl;
	cout << "HourlyWorkers:      " << comp.CountWorkerType(TWorker::HourlyWorker) << endl;
	cout << "Pieces Produced:    " << comp.PiecesProduced() << endl;
	cout << "Pieces Sold:        " << comp.PiecesSold() << endl;
	cout << "Amount Born Before: " << comp.AmountBornBefore(70) << endl;
 
	
	//Employee* test =  comp.FindByShortName("rie");
	Employee* test = comp.LongestEmployee();
	cout << "xxx" << endl;
	test->Print(cout);
	//Employee* LongestEmployee() const;

	delete b;
	delete c;
	delete p;
	delete h;











	/*
	Boss b{ "Markus", "Riegler", "rie", "1234010100", 2010 };
	b.Print(cout);
	b.SetSalary(2500.00);
	b.Print(cout);

	CommissionWorker c{ "Max", "Mustermann", "mmm", "2345091198", 2015 };
	c.Print(cout);
	c.SetPieces(500);
	c.SetRate(3.56);
	c.SetSalary(1000);
	c.Print(cout);

	HourlyWorker h{ "abc", "asfsadfas", "asd", "1234151007", 2009 };
	h.Print(cout);
	h.SetHours(180.2);
	h.SetWage(15.30);
	h.Print(cout);

	PieceWorker p{ "ljfds", "alskjldskj", "abc", "1987080990", 2018 };
	p.Print(cout);
	p.SetPieces(1000);
	p.SetRate(1.98);
	p.Print(cout);

	b.SetSchortName("abcd");
	b.SetSalary(-9);
	b.SetName("abc");
	b.Print(cout);
	*/

	return 0;



}