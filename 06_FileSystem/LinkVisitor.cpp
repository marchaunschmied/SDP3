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
/////////////////////////////////////////////////
// save all links
/////////////////////////////////////////////////
void LinkVisitor::Visit(Link& link) {
	mLinks.push_back(std::make_shared<Link>(link));
}

std::string GetPath(Node::SPtr pLink) {
	//current parentNode
	Node::SPtr parentNode = pLink->GetParent();
	std::string path = "";

	//iterate trough parent nodes until root is reached
	while (parentNode->GetParent() != nullptr) {
		path = parentNode->GetName() + "/" + path;
		parentNode = parentNode->GetParent();
	}
	path += pLink->GetName();		//add file to path
	path = parentNode->GetName() + path;	//add root directory to path
	return path;
}


/////////////////////////////////////////////////
// print saved links
/////////////////////////////////////////////////
void LinkVisitor::Print() const {
	if (mOst.good()) {
		for (Link::SPtr pLink : mLinks) {
			if (pLink != nullptr) {
				mOst << GetPath(pLink)  << " ==> " << GetPath(pLink->GetLink())  << std::endl;
			}
		}
	}
}

