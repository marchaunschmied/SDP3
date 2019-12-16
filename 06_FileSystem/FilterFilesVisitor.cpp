///////////////////////////////////////////////////////////////////////////
// Workfile :		FilterFilesVisitor.cpp
// Author :			Marc Haunschmied
// Date :			16-December-2019
// Description :	Visior prints all files inside of range given in the
//					ctor
// Revision :
///////////////////////////////////////////////////////////////////////////


#include "FilterFilesVisitor.h"
#include <iostream>
FilterFilesVisitor::FilterFilesVisitor(size_t const& minSize, size_t const& maxSize, std::ostream& ost) : mMinSize(minSize), mMaxSize(maxSize), mOst(ost){}

void FilterFilesVisitor::Visit(Folder& folder) {
}

/////////////////////////////////////////////////
// saves all files which are between mMinSize
// and mMaxSize
/////////////////////////////////////////////////
void FilterFilesVisitor::Visit(File& file) {

	 if (file.GetFileSize() > mMinSize && file.GetFileSize() < mMaxSize) {
		
		 //add filtered files to list
		 File::SPtr pFile = std::make_shared<File>(file);
		 mFiles.push_back(pFile);

	 }
}

void FilterFilesVisitor::Visit(Link& link) {
}


/////////////////////////////////////////////////
// prints all files inside the range
/////////////////////////////////////////////////
void FilterFilesVisitor::Print() const {
	if (mOst.good()) {
		mOst << "Files between " << mMinSize << " and " << mMaxSize << " : " << std::endl;
		for (File::SPtr pFile : mFiles) {
			if (pFile != nullptr) {
				//current parentNode
				Node::SPtr parentNode = pFile->GetParent();
				std::string path = "";

				//iterate trough parent nodes until root is reached
				while (parentNode->GetParent() != nullptr) {
					path = parentNode->GetName() + "/" + path;
					parentNode = parentNode->GetParent();
				}
				path += pFile->GetName();		//add file to path
				path = parentNode->GetName() + path;	//add root directory to path

				mOst  << pFile->GetFileSize() << "\t" << path << std::endl;

			}
		}
	}
}