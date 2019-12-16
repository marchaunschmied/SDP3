///////////////////////////////////////////////////////////////////////////
// Workfile :		Folder.cpp
// Author :			Markus Riegler
// Date :			13-December-2019
// Description :	Implementation for class folder derived from class Node
// Revision :		1.0
///////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <iostream>
#include "Folder.h"

///////////////////////////////////////////////////////////////////////////
//Adds the given node into the container
///////////////////////////////////////////////////////////////////////////
std::string const ERROR_CONTAINED = " is already contained in ";
void Folder::Add(Node::SPtr const& node)
{
	if (node == nullptr){
		throw std::string(GetName() + ": null pointer in Folder::Add");
	}
	else if (node.get() == this) {
		throw std::string(GetName() + ": self assignment in Folder::Add");
	}
	else
	{
		auto it = find_if(mNodes.cbegin(), mNodes.cend(), 
						  [&node](auto s) {return node->GetName() == s->GetName(); });
		if (it == mNodes.cend())
		{
			node->SetParent(shared_from_this());
			mNodes.emplace_back(node);
		}
		else
		{
			std::cerr << node->GetName() << ERROR_CONTAINED << GetName() << std::endl;
		}


	}
}

///////////////////////////////////////////////////////////////////////////
//returns indexed child from container
//index out of range -> nullpointer gets returned
///////////////////////////////////////////////////////////////////////////
Node::SPtr Folder::GetChild(size_t index) const
{
	if (index < mNodes.size())
	{
		return mNodes[index];
	}
	else
	{
		return nullptr;
	}
}

///////////////////////////////////////////////////////////////////////////
//Removes given node if contained
///////////////////////////////////////////////////////////////////////////
void Folder::Remove(Node::SPtr const& node)
{
	if (node == nullptr)
	{
		throw std::string(GetName() + ": null pointer in Folder::Remove");
	}
	else
	{
		auto it = find_if(mNodes.cbegin(), mNodes.cend(),
			[&node](auto s) {return node->GetName() == s->GetName(); });
		//found?
		if (it == mNodes.cend()) { return; }
		//when found erase
		mNodes.erase(it);
	}
}

///////////////////////////////////////////////////////////////////////////
//Takes a Visitor and passes it to its childs
///////////////////////////////////////////////////////////////////////////
void Folder::Accept(NodeVisitor& vis)
{
	//visit Folder
	vis.Visit(*this);

	//Visit childs
	for (auto const& n : mNodes)
	{
		n->Accept(vis);
	}
}

///////////////////////////////////////////////////////////////////////////
//CTor passes name to Node-CTor
///////////////////////////////////////////////////////////////////////////
Folder::Folder(std::string const& name): Node{name}
{
}

///////////////////////////////////////////////////////////////////////////
//returns a shared_ptr to itself
///////////////////////////////////////////////////////////////////////////
Node::SPtr Folder::GetFolder()
{
	return shared_from_this();
}
