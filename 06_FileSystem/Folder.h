///////////////////////////////////////////////////////////////////////////
// Workfile :		Folder.h
// Author :			Markus Riegler
// Date :			13-December-2019
// Description :	Header for class folder derived from base class Node
// Revision :		1.0
///////////////////////////////////////////////////////////////////////////

#ifndef FOLDER_H
#define FOLDER_H

#include <memory>
#include <vector>
#include "Node.h"
#include "NodeVisitor.h"


class Folder : public Node, public std::enable_shared_from_this<Folder>{
public:
	//pointer typedefs
	using SPtr = std::shared_ptr<Folder>;

	//override composit functions
	virtual void Add(Node::SPtr const& node) override;
	virtual Node::SPtr GetChild(size_t index) const override;
	virtual void Remove(Node::SPtr const& node) override;

	//interface for Visitors
	virtual void Accept(NodeVisitor& vis) override;

	//CTor
	Folder(std::string const& name);

	//Get functions
	virtual Node::SPtr GetFolder() override;

private:
	//Container for childs
	std::vector<Node::SPtr> mNodes;

};

#endif
