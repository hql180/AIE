#pragma once

class SceneNode;

class Scene
{
public:
	Scene();
	~Scene();

	void UpdateTransforms();

	void SetRoot(SceneNode* pNode);

private:
	SceneNode* root;

};

