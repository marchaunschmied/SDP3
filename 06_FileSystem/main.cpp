#include <iostream>
#include <fstream>

#include "NodeFactory.h"
#include "DumpVisitor.h"
#include "FilterFilesVisitor.h"
#include "LinkVisitor.h"

#include "vld.h"

using namespace std;
int main()
{

	NodeFactory fact;
	DumpVisitor dmp;
	Folder::SPtr root = fact.CreateFolder("/");
	root->Accept(dmp);
	cout << endl;
	ofstream file{ "Test.txt" };
	DumpVisitor dmp2{ &file };

	root->Add(fact.CreateFolder("home"));
	root->Add(fact.CreateFile("test.txt", 64, 10));
	root->Add(fact.CreateFile("abc.txt",128, 7));
	root->Accept(dmp);
	root->Accept(dmp2);
	cout << endl;

	Folder::SPtr bsy = fact.CreateFolder("bsy");
	Folder::SPtr karl = fact.CreateFolder("karl");

	File::SPtr text = fact.CreateFile("text.txt", 32, 15);
	text->Write(80);
	text->Write(800);
	karl->Add(fact.CreateFolder("sepp"));
	karl->Add(text);

	Folder::SPtr karl2 = fact.CreateFolder("karl2");
	Folder::SPtr karl3 = fact.CreateFolder("karl3");
	Folder::SPtr karl4 = fact.CreateFolder("karl4");
	Folder::SPtr karl5 = fact.CreateFolder("karl5");
	File::SPtr text = fact.CreateFile("text", 32, 15);
	text->Write(80);
	text->Write(800);
	karl->Add(fact.CreateFolder("sepp"));
	karl->Add(karl2);
	karl2->Add(karl3);
	karl3->Add(karl4);
	karl4->Add(karl5);

	bsy->Add(karl);
	//bsy->Add(text);
	//bsy->Add(text);

	root->Add(bsy);
	root->Add(fact.CreateLink("link", text));
	root->Accept(dmp);
	cout << endl;


	cout << "////////////////////////////////////////////////" << endl;

	FilterFilesVisitor fVis(10, 500);
	root->Accept(fVis);
	fVis.Print();

	LinkVisitor lVis(cout);
	root->Accept(lVis);
	lVis.Print();

	cout << "////////////////////////////////////////////////" << endl;

	root->Remove(bsy);
	root->Accept(dmp);
	cout << endl;
	auto ptr1 = root->GetChild(1);
	root->Remove(ptr1);
	root->Accept(dmp);
	cout << endl;

	auto ptr = root->GetChild(0);
	if (ptr->GetFolder() != nullptr)
	{
		ptr->Add(fact.CreateFile("franz", 10, 10));
		cout << endl << "Parent of " << ptr->GetName() << ptr->GetParent()->GetName() << endl << endl;
	}
	root->Accept(dmp);
	cout << endl;

	

	


	return 0;
}