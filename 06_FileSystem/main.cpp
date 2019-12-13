#include <iostream>
#include "NodeFactory.h"
#include "DumpVisitor.h"

using namespace std;
int main()
{
	NodeFactory fact;
	DumpVisitor dmp;
	Folder::SPtr root = fact.CreateFolder("/");
	root->Accept(dmp);
	cout << endl;

	root->Add(fact.CreateFolder("home"));
	root->Add(fact.CreateFile("test", 64, 10));
	root->Add(fact.CreateFile("abc",128, 7));
	root->Accept(dmp);
	cout << endl;

	Folder::SPtr bsy = fact.CreateFolder("bsy");
	File::SPtr text = fact.CreateFile("text", 32, 15);
	text->Write(80);
	text->Write(800);
	bsy->Add(text);
	root->Add(bsy);
	root->Add(fact.CreateLink("link", text));
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