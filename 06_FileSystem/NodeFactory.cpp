///////////////////////////////////////////////////////////////////////////
// Workfile :		NodeFactory.cpp
// Author :			Markus Riegler
// Date :			13-December-2019
// Description :	Implementation for class NodeFactory
// Revision :		1.0
///////////////////////////////////////////////////////////////////////////

#include "NodeFactory.h"

///////////////////////////////////////////////////////////////////////////
//each create makes an shared pointer to the specific Object
///////////////////////////////////////////////////////////////////////////
Folder::SPtr NodeFactory::CreateFolder(std::string const& name)
{
	return std::make_shared<Folder>(name);
}

File::SPtr NodeFactory::CreateFile(std::string const& name, size_t const blocksize, size_t const blockcount)
{
	return std::make_shared<File>(name, blocksize, blockcount);
}

Link::SPtr NodeFactory::CreateLink(std::string const& name, Node::SPtr const& link)
{
	return std::make_shared<Link>(name, link);
}
