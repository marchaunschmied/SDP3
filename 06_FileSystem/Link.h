#ifndef LINK_H
#define LINK_H

#include <memory>
#include <string>
#include "Node.h"
#include "NodeVisitor.h"

class Link : public Node {
public:
	using SPtr = std::shared_ptr<Link>;

	virtual void Accept(NodeVisitor& vis) override;

	Link(std::string const& name, Node::SPtr const& link);

private:
	Node::SPtr mLink;
};

#endif
