///////////////////////////////////////////////////////////////////////////
// Workfile :		main.cpp
// Author :			Marc Haunschmied
// Date :			2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Boss.h"
#include "CommissionWorker.h"
#include "Employee.h"
#include "HourlyWorker.h"
#include "PieceWorker.h"
#include "vld.h"

using namespace std;

int main() {

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


	return 0;



}