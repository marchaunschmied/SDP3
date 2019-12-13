///////////////////////////////////////////////////////////////////////////
// Workfile :		File.h
// Author :			Markus Riegler
// Date :			13-December-2019
// Description :	Header for class File derived from base class Node
// Revision :		1.0
///////////////////////////////////////////////////////////////////////////

#ifndef FILE_H
#define FILE_H

#include <memory>
#include <string>
#include "Node.h"
#include "NodeVisitor.h"

class File : public Node {
public:
	//pointer typedef
	using SPtr = std::shared_ptr<File>;

	//interface for Visitor
	virtual void Accept(NodeVisitor& vis) override;

	//simulates writing to a file
	void Write(size_t const bytes);

	//CTor
	File(std::string const& name, size_t const blocksize, size_t const blockcount);

	//Get functions
	size_t GetFileSize() const;
private:
	//information about storage
	size_t mFileSize = 0;
	size_t mBlockSize;
	size_t mBlockCount;
};

#endif
