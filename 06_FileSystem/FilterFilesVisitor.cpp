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
// prints all files inside the range specified
// in mMinSize and mMaxSize
/////////////////////////////////////////////////
void FilterFilesVisitor::Visit(File& file) {

	 if (file.GetFileSize() > mMinSize && file.GetFileSize() < mMaxSize) {
		 //current parentNode
		 Node::SPtr parentNode = file.GetParent();
		 std::string path = "";

		 //iterate trough parent nodes until root is reached
		 while (parentNode->GetParent() != nullptr) {
			 path = parentNode->GetName() + "/" + path;
			 parentNode = parentNode->GetParent();
		 }
		 path += file.GetName();		//add file to path
		 path = parentNode->GetName() + path;	//add root directory to path
		 //mOst << "Pfad: " << path << ": " << file.GetFileSize() << std::endl;
		
		 //add filtered files to list
		 File::SPtr pFile = std::make_shared<File>(file);
		 mFiles.push_back(std::pair<File::SPtr, std::string>(pFile, path));

	 }
}

void FilterFilesVisitor::Visit(Link& link) {
}