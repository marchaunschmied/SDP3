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
		cout << "-----------------------------------------------------------" << endl;
		cout << "add type and Variable without a factory" << endl;
		cout << "-----------------------------------------------------------" << endl;
		SymbolParser parser;
		try
		{
			parser.AddType("integer");
		}
		catch (std::string const& s)
		{
			cerr << s << endl;
		}

		try
		{
			parser.AddVariable("Hugo", "integer");
		}
		catch (std::string const& s)
		{
			cerr << s << endl;
		}
		
		cout << "-----------------------------------------------------------" << endl;
		cout << "Set & Change empty" << endl;
		cout << "-----------------------------------------------------------" << endl;
		parser.SetFactory(&JavaSymbolFactory::GetInstance());
		parser.SetFactory(&JavaSymbolFactory::GetInstance());
		parser.SetFactory(&IECSymbolFactory::GetInstance());
		parser.SetFactory(&JavaSymbolFactory::GetInstance());

		cout << "-----------------------------------------------------------" << endl;
		cout << "Add Types and Variables to Java" << endl;
		cout << "-----------------------------------------------------------" << endl;

		parser.AddType("Button");
		parser.AddType("Hugo");
		parser.AddType("Window");
		parser.AddVariable("mButton", "Button");
		parser.AddVariable("mWin", "Window");

		cout << "-----------------------------------------------------------" << endl;
		cout << "Add Types and Variables to IEC" << endl;
		cout << "-----------------------------------------------------------" << endl;

		parser.SetFactory(&IECSymbolFactory::GetInstance());
		parser.AddType("SpeedController");
		parser.AddType("Hugo");
		parser.AddType("Nero");
		parser.AddVariable("mCont", "SpeedController");
		parser.AddVariable("mHu", "Hugo");

		cout << "-----------------------------------------------------------" << endl;
		cout << "Add more Types and Variables to Java" << endl;
		cout << "-----------------------------------------------------------" << endl;

		parser.SetFactory(&JavaSymbolFactory::GetInstance());
		parser.AddType("Switch");
		parser.AddType("Integer");
		parser.AddVariable("myWin", "Window");
		parser.AddVariable("Counter", "Integer");

		cout << "-----------------------------------------------------------" << endl;
		cout << "Add existing types and Variables to Java" << endl;
		cout << "-----------------------------------------------------------" << endl;

		parser.AddType("Switch");
		parser.AddType("Hugo");
		parser.AddVariable("mWin", "Window");
		parser.AddVariable("Counter", "Integer");

		cout << "-----------------------------------------------------------" << endl;
		cout << "Add more Types and Variables to Java" << endl;
		cout << "-----------------------------------------------------------" << endl;

		parser.SetFactory(&IECSymbolFactory::GetInstance());
		parser.AddType("Integer");
		parser.AddType("Natural");
		parser.AddVariable("ActSpeed", "SpeedController");
		parser.AddVariable("Counter", "Hugo");

		cout << "-----------------------------------------------------------" << endl;
		cout << "Add existing types and Variables to IEC" << endl;
		cout << "-----------------------------------------------------------" << endl;

		parser.AddType("Integer");
		parser.AddType("Hugo");
		parser.AddVariable("mCont", "SpeedController");
		parser.AddVariable("Counter", "Hugo");
		
	}
	catch (exception const& ex)
	{
		cerr << "Error: " << ex.what() << endl;
		return 1;
	}
	catch (bad_alloc const& ex)
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

