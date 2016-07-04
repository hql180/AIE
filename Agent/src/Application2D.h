#pragma once

#include "BaseApplication.h"

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
	Agent*			testAgent;
	Agent*			testAgent1;
	Agent*			testAgent2;
	Agent*			testAgent3;
	Agent*			testAgent4;
	Agent*			testAgent5;
	Agent*			testAgent6;
};