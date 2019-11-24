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
	try {

		//SymbolFactory::SPtr fact = JavaSymbolFactory::GetInstance();

		//JavaSymbolFactory::GetInstance().print();

		/*JavaSymbolFactory& fact = JavaSymbolFactory::GetInstance();

		cout << fact.GetTypeFilename() << endl;
		cout << fact.GetVariableFilename() << endl;

		JavaType::SPtr test = fact.CreateType("integer");
		test->Print(cout);

		JavaVariable::UPtr var1 = fact.CreateVariable("hallo");
		var1->SetType(test);
		var1->Print(cout);

		IECSymbolFactory& factIEC = IECSymbolFactory::GetInstance();

		cout << factIEC.GetTypeFilename() << endl;
		cout << factIEC.GetVariableFilename() << endl;

		IECType::SPtr iecType = factIEC.CreateType("double");
		iecType->Print(cout);

		IECVariable::UPtr iecVar = factIEC.CreateVariable("radius");
		iecVar->SetType(iecType);
		iecVar->Print(cout);*/

		SymbolParser parser;

		parser.SetFactory(&JavaSymbolFactory::GetInstance());
		parser.AddType("Button");
		parser.AddType("Hugo");
		parser.AddType("Window");
		parser.AddVariable("mButton", "Button");
		parser.AddVariable("mWin", "Window");

		parser.SetFactory(&IECSymbolFactory::GetInstance());
		parser.AddType("SpeedController");
		parser.AddType("Hugo");
		parser.AddType("Nero");
		parser.AddVariable("mCont", "SpeedController");
		parser.AddVariable("mHu", "Hugo");

		parser.SetFactory(&JavaSymbolFactory::GetInstance());
		parser.AddVariable("b", "Button");

		parser.SetFactory(&IECSymbolFactory::GetInstance());
		parser.AddType("Hugo");
		parser.AddVariable("mCont", "Hugo");
	}
	catch (exception const& ex)
	{
		cerr << "Error: " << ex.what() << endl;
		return 1;
	}
	catch (std::string const& s)
	{
		cerr << s << endl;
		return 1;
	}
	catch (...)
	{
		cerr << "unhandled exception" << endl;
		return 1;
	}
}

