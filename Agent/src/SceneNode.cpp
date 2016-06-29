#include "SceneNode.h"
#include <algorithm>
#include <fstream>
#include <iostream>


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
	//tParent->AddChild(this);
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

void SceneNode::SaveTransforms(std::ofstream &file)
{
	/*std::ofstream fout("data.dat", std::ios::binary);
	fout.write((char*)&local_transform, sizeof(local_transform));
	fout.close();

	std::cout << "Saved? \n";

	for (auto&it : children)
	{
		it->SaveTransforms(file);
	}*/
}

void SceneNode::LoadTransforms(std::ifstream &file)
{
	/*std::ifstream fout("data.dat", std::ios::binary);

	fout.read((char*)&local_transform, sizeof(local_transform));
	
	fout.close();
	std::cout << "Loaded? \n";

	for (auto&it : children)
	{
		it->LoadTransforms(file);
	}*/
}
