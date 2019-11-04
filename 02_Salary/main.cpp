///////////////////////////////////////////////////////////////////////////
// Workfile :		main.cpp
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

#include "vld.h"

using namespace std;

int main() {

	Company comp("Fa. HSD", "Hagenberg");
	ClientTest client;


	/////////////////////////////////////////////
	// BOSS
	/////////////////////////////////////////////

	Boss* b = new Boss{ "Markus", "Riegler", "rie", "1234010196", 2010 };
	b->SetSalary(2500.0);


	/////////////////////////////////////////////
	// CommissionWorkers
	/////////////////////////////////////////////

	CommissionWorker* c = new CommissionWorker{ "Marc", "Haunschmied", "hmm", "9999021191", 2009 };
	c->SetSalary(1750.0);
	c->SetPieces(250);
	c->SetRate(4.32);

	CommissionWorker* c1 = new CommissionWorker{ "David", "Alaba", "ald", "3333010192", 2013 };
	c1->SetSalary(2300.0);
	c1->SetPieces(175);
	c1->SetRate(6.212);

	CommissionWorker* c2 = new CommissionWorker{ "Marko" , "Arnautovic", "arm", "4123020289", 2009 };
	c2->SetSalary(3000.0);
	c2->SetPieces(65);
	c2->SetRate(3.3);

	/////////////////////////////////////////////
	// Hourly Workers
	/////////////////////////////////////////////

	HourlyWorker* h = new HourlyWorker{ "Max", "Mustermann", "mam", "1234041101", 2017 };
	h->SetHours(187.5);
	h->SetWage(14.6);

	HourlyWorker* h1 = new HourlyWorker{ "Fritz", "Phantom", "phf", "9999050696", 2009 };
	h1->SetHours(150);
	h1->SetWage(12.1);

	/////////////////////////////////////////////
	// Piece Workers
	/////////////////////////////////////////////

	PieceWorker* p = new PieceWorker{ "Arnold", "Schwarzenegger", "sca", "4711300747", 1967 };
	p->SetPieces(332);
	p->SetRate(3.56);


	PieceWorker* p1 = new PieceWorker{ "Christoph", "Waltz", "wac", "5234030356", 1978 };
	p1->SetPieces(123);
	p1->SetRate(5.56);


	PieceWorker* p2 = new PieceWorker{ "Til", "Schweiger", "sct", "5555040467", 1988 };
	p2->SetPieces(441);
	p2->SetRate(2.56);


	PieceWorker* p3 = new PieceWorker{ "Johnny", "Depp", "dej", "6234050565", 1998 };
	p3->SetPieces(643);
	p3->SetRate(1.96);

	PieceWorker* p4 = new PieceWorker{ "Leonardo", "Di Caprio", "dil", "5631060672", 2000 };
	p4->SetPieces(355);
	p4->SetRate(5.56);




	comp.AddEmployee(b);
	comp.AddEmployee(c);
	comp.AddEmployee(c1);
	comp.AddEmployee(c2);

	comp.AddEmployee(h);
	comp.AddEmployee(h1);

	comp.AddEmployee(p);
	comp.AddEmployee(p1);
	comp.AddEmployee(p2);
	comp.AddEmployee(p3);
	comp.AddEmployee(p4);

	client.Test(&comp);

	cout << endl << endl << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl << endl;

	Company comp1{ "Microsoft", "Washington" };
	client.Test(&comp1);

	cout << endl << endl << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl << endl;

	Company comp2{ "VOEST Alpine", "Linz" };
	comp2.AddEmployee(c2);
	comp2.AddEmployee(p4);
	
	client.Test(&comp2);
	cout << endl << endl << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl << endl;

	comp2.DeleteEmployee("arm");

	client.Test(&comp2);
	cout << endl << endl << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl << endl;

	comp2.AddEmployee(c2);
	comp2.AddEmployee(h1);

	client.Test(&comp2);

	cout << endl << endl << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl << endl;
	
	comp2.DeleteEmployee("phf");
	comp2.DeleteEmployee("arm");
	comp2.DeleteEmployee("dil");

	client.Test(&comp2);

	cout << endl << endl << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl << endl;

	comp2.DeleteEmployee("hmm");

	client.Test(&comp2);


	delete b;

	delete c;
	delete c1;
	delete c2;

	delete p;
	delete p1;
	delete p2;
	delete p3;
	delete p4;

	delete h;
	delete h1;

	return 0;
}