#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "Object.h"
#include "Folder.h"
#include "File.h"
#include "Link.h"
#include "NodeVisitor.h"
#include "NodeFactory.h"

class FileSystem : public Object {
public:
	void Visit(NodeVisitor::SPtr visitor);
private:
	Folder mRoot;
	NodeFactory fact;
};

#endif
