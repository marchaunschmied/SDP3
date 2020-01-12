///////////////////////////////////////////////////////////////////////////
// Workfile :		Link.cpp
// Author :			Markus Riegler
// Date :			13-December-2019
// Description :	Implemantation for class Link derived from class Node
// Revision :		1.0
///////////////////////////////////////////////////////////////////////////

#include "Link.h"

///////////////////////////////////////////////////////////////////////////
//execute Visitor
///////////////////////////////////////////////////////////////////////////
void Link::Accept(NodeVisitor& vis)
{
	vis.Visit(*this);
}

///////////////////////////////////////////////////////////////////////////
//CTor sets name and linked object
///////////////////////////////////////////////////////////////////////////
Link::Link(std::string const& name, Node::SPtr const& link): Node{name}
{
	if (link == nullptr)
	{
		throw std::string("nullpointer in Link");
	}
	else
	{
		mLink = link;
	}
}

Node::SPtr Link::GetLink() const {
	return mLink;
}