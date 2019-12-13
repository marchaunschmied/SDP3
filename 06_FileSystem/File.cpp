#include <iostream>
#include "File.h"

void File::Accept(NodeVisitor& vis)
{
	vis.Visit(*this);
}

void File::Write(size_t const bytes)
{
	if ((mFileSize + bytes) > (mBlockCount * mBlockSize))
	{
		std::cout << GetName() << " is full, couldn't write last " << (mFileSize + bytes) - (mBlockCount * mBlockSize) << " bytes." << std::endl;
		mFileSize = mBlockCount * mBlockSize;
	}
	else
	{
		mFileSize += bytes;
	}
}

File::File(std::string const& name, size_t const blocksize, size_t const blockcount): 
		Node{name}, mBlockSize{blocksize}, mBlockCount{blockcount}
{
}

size_t File::GetFileSize() const
{
	return mFileSize;
}
