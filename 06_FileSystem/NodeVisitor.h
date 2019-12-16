#ifndef NODEVISITOR_H
#define NODEVISITOR_H

#include <memory>

class File;
class Folder;
class Link;

class NodeVisitor {
public:
	using SPtr = std::shared_ptr<NodeVisitor>;


	virtual void Visit(Folder& folder) = 0;
	virtual void Visit(File& file) = 0;
	virtual void Visit(Link& link) = 0;

protected:
	NodeVisitor() = default;
};

#endif
