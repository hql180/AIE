#include "Sprite.h"
#include "Texture.h"
#include "SpriteBatch.h"

#include <fstream>

Sprite::Sprite()
{
	m_sprite = new Texture("./bin/textures/crate.png");
	m_crate2 = new Sprite("./bin/textures/crate.png");
	
	AddChild(m_crate2);
	m_crate2->SetLocalTransform(Matrix3::CreateTranslation(Vector3(0, -500, 1)));
	m_crate2->m_rotation = 0;
	
	m_position = Vector3(640, 700, 1);
	m_velocity = Vector3(0, 0, 0);
	m_rotation = 0;
	
}

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
	if (children.size() > 0)
	{
		local_transform =  Matrix3::CreateScale(Vector3(.1, .1, 1)) * Matrix3::CreateRotation(m_rotation) * Matrix3::CreateTranslation(m_position);

		m_velocity.m_y -= 250 * dt;

		m_position = m_position + m_velocity * dt;

		m_rotation += 2*dt;

		if (m_position.m_y <= 0)
		{
			m_position.m_y = 10;
			m_velocity.m_y = -.9 * m_velocity.m_y;
		}
	
		m_crate2->Update(dt);
	}
	else
	{
		local_transform = Matrix3::CreateRotation(m_rotation += 3 * dt) * Matrix3::CreateTranslation(Vector3(0, -500, 1));
	}

}

void Sprite::Draw(SpriteBatch* spritebatch)
{
	spritebatch->drawSpriteTransformed3x3(m_sprite, (float*)global_transform.m);

	if (children.size() > 0)
	{
		m_crate2->Draw(spritebatch);
	}
}

void Sprite::SaveTransforms(std::ofstream & file)
{
	file.write((char*)&m_position, sizeof(m_position));
	file.write((char*)&m_velocity, sizeof(m_velocity));	
	file.write((char*)&m_rotation, sizeof(m_rotation));

	for (auto&it : children)
	{
		it->SaveTransforms(file);
	}
}

void Sprite::LoadTransforms(std::ifstream & file)
{
	file.read((char*)&m_position, sizeof(m_position));
	file.read((char*)&m_velocity, sizeof(m_velocity));
	file.read((char*)&m_rotation, sizeof(m_rotation));

	for (auto&it : children)
	{
		it->LoadTransforms(file);
	}
}


