#include "SceneNode.h"
#include <algorithm>


SceneNode::SceneNode()
{
	parent = nullptr;
}


SceneNode::~SceneNode()
{
}

void SceneNode::SetParent(SceneNode * tParent)
{
	parent = tParent;
}

void SceneNode::AddChild(SceneNode * Child)
{
	children.push_back(Child);
	Child->SetParent(this);
}

void SceneNode::RemoveChild(SceneNode * Child)
{
	children.erase(std::remove(children.begin(), children.end(), Child), children.end());
	delete Child;
}

void SceneNode::UpdateTransforms()
{
	if (parent != nullptr)
		global_transform = local_transform * parent->global_transform;
	else
		global_transform = local_transform;

	for (auto&it : children)
	{
		it->UpdateTransforms();
	}
}
