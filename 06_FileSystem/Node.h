#ifndef NODE_H
#define NODE_H

#include <memory>
#include <string>

#include "Object.h"
#include "NodeVisitor.h"

class Node : public Object{
public:
	using SPtr = std::shared_ptr<Node>;
	using WPtr = std::weak_ptr<Node>;

	virtual void Add(Node::SPtr const& node);
	virtual void Remove(Node::SPtr const& node);
	virtual Node::SPtr GetChild(size_t index) const;
	

	virtual void Accept(NodeVisitor::SPtr const& vis) = 0;

	void SetName(std::string const& name);
	void SetParent(Node::SPtr parent);

	Node::SPtr GetParent() const;
	virtual Node::SPtr GetComposite();
	std::string GetName() const;

protected:
	Node(std::string const& name);

private:
	std::string mName;
	Node::WPtr mParent;
};

#endif
