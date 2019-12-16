#ifndef FILTERFILESVISITOR_H
#define FILTERFILESVISITOR_H

#include <list>
#include "Object.h"
#include "NodeVisitor.h"
#include "File.h"
#include "Folder.h"
#include "Link.h"

class FilterFilesVisitor : public Object, public NodeVisitor {
public:
	virtual void Visit(Folder& folder) override;
	virtual void Visit(File& file) override;
	virtual void Visit(Link& link) override;
private:
	std::list<File::SPtr> mFiles;
};

#endif
