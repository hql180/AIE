#include "Scene.h"
#include "SceneNode.h"

Scene::Scene()
{
	
}


Scene::~Scene()
{
}

void Scene::UpdateTransforms()
{
	root->UpdateTransforms();
}

void Scene::SetRoot(SceneNode * pNode)
{
	root = pNode;
}

void Scene::SaveTransforms(std::ofstream& file)
{
	root->SaveTransforms(file);
}

void Scene::LoadTransforms(std::ifstream& file)
{
	root->LoadTransforms(file);
}
