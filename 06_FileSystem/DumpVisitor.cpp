#include <iostream>
#include "DumpVisitor.h"

void DumpVisitor::Visit(Folder& folder)
{
	std::cout << "Folder: " << folder.GetName() << std::endl;
}

void DumpVisitor::Visit(File& file)
{
	std::cout << "File: " << file.GetName() << std::endl;
}

void DumpVisitor::Visit(Link& link)
{
	std::cout << "Link: " << link.GetName() << std::endl;
}
