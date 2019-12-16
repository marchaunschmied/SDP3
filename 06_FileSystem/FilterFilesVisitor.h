///////////////////////////////////////////////////////////////////////////
// Workfile :		FilterFilesVisitor.h
// Author :			Marc Haunschmied
// Date :			16-December-2019
// Description :	Visior prints all files inside of range given in the
//					ctor
// Revision :
///////////////////////////////////////////////////////////////////////////
#ifndef FILTERFILESVISITOR_H
#define FILTERFILESVISITOR_H

#include <iostream>
#include <list>
#include "Object.h"
#include "NodeVisitor.h"
#include "File.h"
#include "Folder.h"
#include "Link.h"



class FilterFilesVisitor : public Object, public NodeVisitor {
public:

	FilterFilesVisitor(size_t const& minSize, size_t const& maxSize, std::ostream& ost = std::cout);

	virtual void Visit(Folder& folder) override;
	virtual void Visit(File& file) override;
	virtual void Visit(Link& link) override;

	void Print() const;

private:
	std::list<File::SPtr> mFiles;

	std::ostream& mOst;

	size_t mMinSize;
	size_t mMaxSize;
};

#endif
