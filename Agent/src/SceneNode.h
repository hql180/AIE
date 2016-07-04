#pragma once
#include <vector>

#include "Matrix3.h"
#include "Scene.h"
class SceneNode : public Scene
{
public:
	SceneNode();
	~SceneNode();

	void SetParent(SceneNode* tParent);
	void AddChild(SceneNode* Child);
	void RemoveChild(SceneNode* Child);
	void UpdateTransforms();
	virtual void SaveTransforms(std::ofstream & file);
	virtual void LoadTransforms(std::ifstream & file);


protected:
	std::vector<SceneNode*> children;
	SceneNode* parent;

	Matrix3 local_transform;

	Matrix3 global_transform;
};

