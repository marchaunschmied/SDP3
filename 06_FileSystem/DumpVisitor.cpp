///////////////////////////////////////////////////////////////////////////
// Workfile :		DumpVisitor.cpp
// Author :			Markus Riegler
// Date :			15-December-2019
// Description :	Implementation for class DumpVisitor implements interface 
//					NodeVisitor
// Revision :		1.0
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "DumpVisitor.h"

///////////////////////////////////////////////////////////////////////////
//Visits Folder
///////////////////////////////////////////////////////////////////////////
void DumpVisitor::Visit(Folder& folder)
{
	if (ost->good())
	{
		//Calc right depth
		CheckPrev(folder.GetParent());
		//Print information
		PrintSpace();
		if (folder.GetName() != "/") {	//dont print slash when root folder
			*ost << folder.GetName() << "/" << std::endl;
		}
		else {
			*ost << folder.GetName() << std::endl;
		}
		
		//Set Values after Folder
		++mDepth;
		mPrev = folder.GetFolder();
	}
}

///////////////////////////////////////////////////////////////////////////
//Visits File
///////////////////////////////////////////////////////////////////////////
void DumpVisitor::Visit(File& file)
{
	if (ost->good())
	{
		//Calc right depth
		CheckPrev(file.GetParent());
		//Print information
		PrintSpace();
		*ost << file.GetName() << std::endl;
	}
}

///////////////////////////////////////////////////////////////////////////
//Visits Link
///////////////////////////////////////////////////////////////////////////
void DumpVisitor::Visit(Link& link)
{
	if (ost->good())
	{
		//Calc right depth
		CheckPrev(link.GetParent());
		//Print information
		PrintSpace();
		*ost << link.GetName() << std::endl;
	}
}

///////////////////////////////////////////////////////////////////////////
//CTor sets the stream
///////////////////////////////////////////////////////////////////////////
DumpVisitor::DumpVisitor(std::ostream* stream): ost{stream}
{
	if (stream == nullptr)
	{
		throw std::string{ "Nullpointer in DumpVisitor CTor" };
	}
}

///////////////////////////////////////////////////////////////////////////
//Prints the needed formation
///////////////////////////////////////////////////////////////////////////
void DumpVisitor::PrintSpace() const
{
	for (size_t i = 0; i < mDepth; ++i)
	{
		*ost << " |";
	}
	*ost << "--";
}

///////////////////////////////////////////////////////////////////////////
//Calculates depth
//Gets Parent of currently visited Node
///////////////////////////////////////////////////////////////////////////
void DumpVisitor::CheckPrev(Node::SPtr const& node)
{
	//nullpointer -> root directory
	if (node == nullptr) 
	{ 
		mDepth = 0;
		return;
	}
	//previuos was root directory
	if (mPrev == nullptr)
	{

		mDepth = 1;
	}
	else
	{
		//walk with mPrev backwards until right position is reached
		while (mPrev->GetName() != node->GetName() && mDepth > 0)
		{
			--mDepth;
			//one up
			mPrev = mPrev->GetParent();
			//if nullpointer is reached -> in root directory
			if (mPrev == nullptr) { return; }
		}
	}
}


