///////////////////////////////////////////////////////////////////////////
// Workfile :		FileSystem.cpp
// Author :			Marc Haunschmied
// Date :			16-December-2019
// Description :	Test class for filesystem implementation
// Revision :
///////////////////////////////////////////////////////////////////////////

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
	FileSystem();

	void Visit(NodeVisitor& visitor);

private:
	Folder::SPtr mRoot;
	NodeFactory fact;

	void Test();
};

#endif
