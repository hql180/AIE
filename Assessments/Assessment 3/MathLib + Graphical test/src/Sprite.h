#pragma once
#include "SceneNode.h"
#include "Vector3.h"

class Texture;
class SpriteBatch;


class Sprite : public SceneNode
{
public:
	Sprite();
	Sprite(const char* szPath);
	~Sprite();

	void SetLocalTransform(Matrix3 mat3);
			
	void Update(float dt);
	void Draw(SpriteBatch* spritebatch);

	virtual void SaveTransforms(std::ofstream &file);
	virtual void LoadTransforms(std::ifstream &file);

private:
	Texture* m_sprite;
	Sprite* m_crate2;

	Vector3 m_position;
	Vector3 m_velocity;

	float m_rotation;
};

