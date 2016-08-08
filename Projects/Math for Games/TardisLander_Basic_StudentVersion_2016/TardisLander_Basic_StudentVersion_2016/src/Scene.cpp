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
