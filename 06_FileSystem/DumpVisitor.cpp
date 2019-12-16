#include <iostream>
#include "DumpVisitor.h"

void DumpVisitor::Visit(Folder& folder)
{
	if (ost->good())
	{
		CheckPrev(folder.GetParent());
		PrintSpace();
		*ost << folder.GetName() << std::endl;
		++mDepth;
		prev = folder.GetName();
	}
}

void DumpVisitor::Visit(File& file)
{
	if (ost->good())
	{
		CheckPrev(file.GetParent());
		PrintSpace();
		*ost << file.GetName() << std::endl;
	}
}

void DumpVisitor::Visit(Link& link)
{
	if (ost->good())
	{
		CheckPrev(link.GetParent());
		PrintSpace();
		*ost << link.GetName() << std::endl;
	}
}

DumpVisitor::DumpVisitor(std::ostream* stream): ost{stream}
{
	if (stream == nullptr)
	{
		throw std::string{ "Nullpointer in DumpVisitor CTor" };
	}
}

void DumpVisitor::PrintSpace() const
{
	for (size_t i = 0; i < mDepth; ++i)
	{
		*ost << " |";
	}
	*ost << "--";
}

void DumpVisitor::CheckPrev(Node::SPtr const& node)
{
	if (node == nullptr) 
	{ 
		mDepth = 0;
		return;
	}
	if (prev != node->GetName() && mDepth > 0)
	{
		//while 
		--mDepth;
		prev = node->GetName();
	}
}


