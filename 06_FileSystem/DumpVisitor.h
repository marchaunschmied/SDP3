#ifndef DUMPVISITOR_H
#define DUMPVISITOR_H

#include "Object.h"
#include "NodeVisitor.h"
#include "File.h"
#include "Folder.h"
#include "Link.h"

class DumpVisitor : public Object, public NodeVisitor {
public:
	virtual void Visit(Folder& folder) override;
	virtual void Visit(File& file) override;
	virtual void Visit(Link& link) override;
private:
	size_t mDepth = 0;
};

#endif
