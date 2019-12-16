///////////////////////////////////////////////////////////////////////////
// Workfile :		LinkVisitor.cpp
// Author :			Marc Haunschmied
// Date :			16-December-2019
// Description :	Filters all Links in the filesystem
// Revision :
///////////////////////////////////////////////////////////////////////////


#include <memory>
#include "Link.h"
#include "LinkVisitor.h"

LinkVisitor::LinkVisitor(std::ostream& ost) : mOst(ost){}

void LinkVisitor::Visit(Folder& folder)
{
}

void LinkVisitor::Visit(File& file)
{
}

void LinkVisitor::Visit(Link& link){
	mLinks.push_back(std::make_shared<Link>(link));
	mOst << link.GetName() << ": " << link.GetLink()->GetName() << std::endl;
}
