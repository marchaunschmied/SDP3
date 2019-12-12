#ifndef DUMPVISITOR_H
#define DUMPVISITOR_H

#include "Object.h"
#include "NodeVisitor.h"

class DumpVisitor : public Object, public NodeVisitor {
public:
	virtual void Visit(Folder::SPtr folder) override;
	virtual void Visit(File::SPtr file) override;
	virtual void Visit(Link::SPtr link) override;
private:
	size_t mDepth = 0;
};

#endif
