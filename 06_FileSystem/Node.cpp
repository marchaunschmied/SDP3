#include "Node.h"


void Node::Add(Node::SPtr const& node)
{
	throw std::string("Add not implemented in base class Node");
}

void Node::Remove(Node::SPtr const& node)
{
	throw std::string("Remove not implemented in base class Node");
}

Node::SPtr Node::GetChild(size_t index) const
{
	return nullptr;
}

void Node::SetName(std::string const& name)
{
	if (name.size() > 0)
	{
		mName = name;
	}
}

void Node::SetParent(Node::SPtr parent)
{
	mParent = parent;
}

Node::SPtr Node::GetParent() const
{
	return mParent.lock();
}

Node::SPtr Node::GetComposite()
{
	return nullptr;
}

std::string Node::GetName() const
{
	return mName;
}

Node::Node(std::string const& name): mName{name}
{
}
