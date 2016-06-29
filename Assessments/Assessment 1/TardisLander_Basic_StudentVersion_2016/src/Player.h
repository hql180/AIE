#pragma once


#include "Vector3.h"
#include "SceneNode.h"

class SpriteBatch;
class Texture;
class Sprite;

class Player : public SceneNode
{
public:
	Player();
	~Player();

	void Update(float dt);
	void Draw(SpriteBatch* batch);
	void Reset();

	inline bool IsDead() {return m_bIsDead;}
	inline bool HasLanded() {return m_bHasLanded;}

private:
	Texture* m_sprite;
	Sprite* m_pFireSprite;

	bool m_bFlameOn;
	float m_rotation;
	
	Vector3 m_velocity;
	Matrix3 m_gravity;
	bool m_bIsDead;
	bool m_bHasLanded;
};

