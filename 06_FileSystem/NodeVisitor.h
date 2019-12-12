#ifndef NODEVISITOR_H
#define NODEVISITOR_H

#include "Folder.h"
#include "File.h"
#include "Link.h"

class NodeVisitor {
public:
	using SPtr = std::shared_ptr<NodeVisitor>;

	virtual void Visit(Folder::SPtr folder) = 0;
	virtual void Visit(File::SPtr file) = 0;
	virtual void Visit(Link::SPtr link) = 0;

protected:
	NodeVisitor() = default;
};

#endif
