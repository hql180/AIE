#include "Sprite.h"
#include "Texture.h"
#include "SpriteBatch.h"

Sprite::Sprite(const char* szPath)
{
	m_sprite = new Texture(szPath);	
}

Sprite::~Sprite()
{
	delete m_sprite;
}

void Sprite::SetLocalTransform(Matrix3 mat3)
{
	local_transform = mat3;
}

void Sprite::Update(float dt) 
{
}

void Sprite::Draw(SpriteBatch* spritebatch)
{
	spritebatch->drawSpriteTransformed3x3(m_sprite, (float*)global_transform.m);	
}