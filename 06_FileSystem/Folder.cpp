#include <algorithm>
#include "Folder.h"

void Folder::Add(Node::SPtr const& node)
{
	if (node == nullptr)
	{
		throw std::string(GetName() + ": null pointer in Folder::Add");
	}
	else
	{
		node->SetParent(shared_from_this());
		mNodes.emplace_back(node);
	}
}

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

void Folder::Remove(Node::SPtr const& node)
{
	if (node == nullptr)
	{
		throw std::string(GetName() + ": null pointer in Folder::Remove");
	}
	else
	{
		auto it = std::find(mNodes.cbegin(), mNodes.cend(), node);
		mNodes.erase(it);
	}
}

void Folder::Accept(NodeVisitor::SPtr const& vis)
{
	vis->Visit(this);

	for (auto const& n : mNodes)
	{
		n->Accept(vis);
	}
}

Folder::Folder(std::string const& name): Node{name}
{
}

Node::SPtr Folder::GetComposite()
{
	return shared_from_this();
}
