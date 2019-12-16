///////////////////////////////////////////////////////////////////////////
// Workfile :		main.cpp
// Author :			Marc Haunschmied
// Date :			16-December-2019
// Description :	Linux Filesystem is created and tested
// Revision :
///////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <fstream>

#include "NodeFactory.h"
#include "DumpVisitor.h"
#include "FilterFilesVisitor.h"
#include "LinkVisitor.h"
#include "FileSystem.h"

#include "vld.h"

using namespace std;
int main()
{
	try {
		
		//new filesystem is created
		FileSystem linux;

		size_t const minSize = 0;
		size_t const maxSize = 10000000; //10M

		//some visitors
		DumpVisitor dVis;
		FilterFilesVisitor fVis(minSize, maxSize); 
		LinkVisitor lVis;

	

		cout << "=============== D U M P ====================" << endl;
		linux.Visit(dVis);
		cout << "*************** L I N K ********************" << endl;
		linux.Visit(lVis);
		lVis.Print();
		cout << "************* F I L T E R ******************" << endl;
		linux.Visit(fVis);
		fVis.Print();
		cout << "============================================" << endl;


		size_t const smallMaxSize = 1024;
		//only small files
		FilterFilesVisitor fSmallVis(minSize, smallMaxSize);
		linux.Visit(fSmallVis);
		fSmallVis.Print();

		//output to text file
		ofstream file("Test.txt");
		DumpVisitor dVisFile(&file);
		linux.Visit(dVisFile);
	
	}
	catch (std::string & ex) {
		cerr << ex << endl;
	}
	
	return 0;
}