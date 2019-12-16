///////////////////////////////////////////////////////////////////////////
// Workfile :		Link.h
// Author :			Markus Riegler
// Date :			13-December-2019
// Description :	Header for class Link derived from base class Node
// Revision :		1.0
///////////////////////////////////////////////////////////////////////////

#ifndef LINK_H
#define LINK_H

#include <memory>
#include <string>
#include "Node.h"
#include "NodeVisitor.h"

class Link : public Node {
public:
	//pointer typedef
	using SPtr = std::shared_ptr<Link>;

	//interface for Visitors
	virtual void Accept(NodeVisitor& vis) override;

	//CTor
	Link(std::string const& name, Node::SPtr const& link);

	Node::SPtr GetLink() const;

private:
	//linked object
	Node::SPtr mLink;
};

#endif
