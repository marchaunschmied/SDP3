///////////////////////////////////////////////////////////////////////////
// Workfile :		main.cpp
// Author :			Marc Haunschmied
// Date :			21-November-2019
// Description :	
// Revision :
///////////////////////////////////////////////////////////////////////////




#include <iostream>


#include "SymbolParser.h"

#include "SymbolFactory.h"
#include "JavaSymbolFactory.h"
#include "IECSymbolFactory.h"

#include "Symbol.h"
#include "JavaType.h"
#include "IECType.h"
#include "JavaVariable.h"
#include "IECVariable.h"

using namespace std;

int main(){
	
	//SymbolFactory::SPtr fact = JavaSymbolFactory::GetInstance();
	
	//JavaSymbolFactory::GetInstance().print();
	
	JavaSymbolFactory fact;

	JavaType::SPtr test = fact.CreateType("integer");
	test->Print(cout);

	JavaVariable::UPtr var1 = fact.CreateVariable("hallo");
	var1->SetType(test);
	var1->Print(cout);

	IECSymbolFactory factIEC;

	IECType::SPtr iecType = factIEC.CreateType("double");
	iecType->Print(cout);

	IECVariable::UPtr iecVar = factIEC.CreateVariable("radius");
	iecVar->SetType(iecType);
	iecVar->Print(cout);


	/*std::cout << "Hello World!\n"; 
	SymbolParser pars;

	std::list<Type::SPtr> l;

	Type::SPtr javaElem = make_shared<JavaType>();
	Type::SPtr iecElem = make_shared<IECType>();
	javaElem->ParseFromLine("class double");
	iecElem->ParseFromLine("TYPE integer");

	l.push_back(javaElem);
	l.push_back(iecElem);



	for (Type::SPtr p : l) {
		p->Print(cout);
	}

	//==================================

	//std::list<Variable::UPtr> vl;

	Variable::UPtr javaVar = make_unique<JavaVariable>();
	Variable::UPtr iecVar = make_unique<IECVariable>();
	javaVar->ParseFromLine("double salary");
	iecVar->ParseFromLine("integer counter");

	//vl.push_back(javaVar);
	//vl.push_back(iecVar);

	javaVar->Print(cout);
	iecVar->Print(cout);
	*/
}

