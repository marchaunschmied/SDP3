#include "Link.h"

void Link::Accept(NodeVisitor::SPtr const& vis)
{
	vis->Visit(this);
}

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
