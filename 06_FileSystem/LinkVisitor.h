///////////////////////////////////////////////////////////////////////////
// Workfile :		LinkVisitor.h
// Author :			Marc Haunschmied
// Date :			16-December-2019
// Description :	Filters all Links in the filesystem
// Revision :
///////////////////////////////////////////////////////////////////////////


#ifndef LINKVISITOR_H
#define LINKVISITOR_H

#include <iostream>
#include <list>
#include "File.h"
#include "Folder.h"
#include "Link.h"


class LinkVisitor : public Object, public NodeVisitor {
public:

	LinkVisitor(std::ostream& ost = std::cout);

	virtual void Visit(Folder& folder) override;
	virtual void Visit(File& file) override;
	virtual void Visit(Link& link) override;

	void Print() const;

private:
	std::list<Link::SPtr> mLinks;

	std::ostream& mOst;
};

#endif