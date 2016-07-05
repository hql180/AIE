#pragma once

#include "BaseApplication.h"
#include <vector>

class SpriteBatch;
class Texture;
class Font;
class Agent;

class Application2D : public BaseApplication {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual bool update(float deltaTime);
	virtual void draw();

protected:

	SpriteBatch*	m_spriteBatch;
	Texture*		m_texture;
	Font*			m_font;

	std::vector<Agent*> agents;	
};