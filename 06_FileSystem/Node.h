///////////////////////////////////////////////////////////////////////////
// Workfile :		Node.h
// Author :			Markus Riegler
// Date :			13-December-2019
// Description :	Header for base class Node
// Revision :		1.0
///////////////////////////////////////////////////////////////////////////
#ifndef NODE_H
#define NODE_H

#include <memory>
#include <string>

#include "Object.h"
//needed to not get an circular inclusion
class NodeVisitor;

class Node : public Object {
public:
	//pointer typedefs
	using SPtr = std::shared_ptr<Node>;
	using WPtr = std::weak_ptr<Node>;

	//Composit functions for Folder
	virtual void Add(Node::SPtr const& node);
	virtual void Remove(Node::SPtr const& node);
	virtual Node::SPtr GetChild(size_t index) const;
	
	//interface for Visitors
	virtual void Accept(NodeVisitor& vis) = 0;

	//Set functions
	void SetName(std::string const& name);
	void SetParent(Node::SPtr parent);

	//Get functions
	Node::SPtr GetParent() const;
	virtual Node::SPtr GetFolder();
	std::string GetName() const;

protected:
	//protected CTor -> abstract class
	Node(std::string const& name);

private:
	std::string mName;
	Node::WPtr mParent;
};

#endif
