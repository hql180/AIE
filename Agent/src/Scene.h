#pragma once

#include<fstream>

class SceneNode;

class Scene
{
public:
	Scene();
	~Scene();

	void UpdateTransforms();

	void SetRoot(SceneNode* pNode);

	void SaveTransforms(std::ofstream &file);
	void LoadTransforms(std::ifstream &file);

private:
	SceneNode* root;

};

