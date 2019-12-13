#ifndef NODEFACTORY_H
#define NODEFACTORY_H

#include "Folder.h"
#include "File.h"
#include "Link.h"
#include "Object.h"

class NodeFactory : public Object {
public:
	Folder::SPtr CreateFolder(std::string const& name);
	File::SPtr CreateFile(std::string const& name, size_t const blocksize, size_t const blockcount);
	Link::SPtr CreateLink(std::string const& name, Node::SPtr const& link);
};

#endif
