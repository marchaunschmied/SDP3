#ifndef FOLDER_H
#define FOLDER_H

#include <memory>
#include <vector>
#include "Node.h"
#include "NodeVisitor.h"


class Folder : public Node, public std::enable_shared_from_this<Folder>{
public:
	using SPtr = std::shared_ptr<Folder>;

	virtual void Add(Node::SPtr const& node) override;
	virtual Node::SPtr GetChild(size_t index) const override;
	virtual void Remove(Node::SPtr const& node) override;

	virtual void Accept(NodeVisitor& vis) override;

	Folder(std::string const& name);
	virtual Node::SPtr GetComposite() override;

private:
	std::vector<Node::SPtr> mNodes;

};

#endif
