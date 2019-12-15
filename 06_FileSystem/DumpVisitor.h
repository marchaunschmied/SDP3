///////////////////////////////////////////////////////////////////////////
// Workfile :		DumpVisitor.h
// Author :			Markus Riegler
// Date :			15-December-2019
// Description :	Header for class File derived from base class Node
// Revision :		1.0
///////////////////////////////////////////////////////////////////////////

#ifndef DUMPVISITOR_H
#define DUMPVISITOR_H

#include "Object.h"
#include "NodeVisitor.h"
#include "File.h"
#include "Folder.h"
#include "Link.h"

class DumpVisitor : public Object, public NodeVisitor {
public:
	//Function for every Node-Type
	virtual void Visit(Folder& folder) override;
	virtual void Visit(File& file) override;
	virtual void Visit(Link& link) override;

	//Ctor sets stream
	DumpVisitor(std::ostream* stream = &std::cout);
private:
	size_t mDepth = 0;
	std::string prev = { 0 };
	std::ostream* ost;
	
	//Prints format
	void PrintSpace() const;
	//changes depth
	void CheckPrev(Node::SPtr const& node);
};

#endif
