#ifndef FILTERFILESVISITOR_H
#define FILTERFILESVISITOR_H

#include <list>
#include "Object.h"
#include "NodeVisitor.h"

class FilterFilesVisitor : public Object, public NodeVisitor {
public:
	virtual void Visit(Folder::SPtr folder) override;
	virtual void Visit(File::SPtr file) override;
	virtual void Visit(Link::SPtr link) override;
private:
	std::list<File::SPtr> mFiles;
};

#endif
