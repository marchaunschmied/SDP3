#ifndef FILE_H
#define FILE_H

#include <memory>
#include <string>
#include "Node.h"

class File : public Node {
public:
	using SPtr = std::shared_ptr<File>;

	void Write(size_t const bytes);

	File(std::string const& name, size_t const blocksize, size_t const blockcount);
	size_t GetFileSize() const;
private:
	size_t mFileSize = 0;
	size_t mBlockSize;
	size_t mBlockCount;
};

#endif
