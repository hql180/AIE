#pragma once
#include "Application.h"
class SpriteBatch;
class Tree;
class Texture;

class TreeDemo : public Application
{
public:

	// assets loaded in constructor
	TreeDemo(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title);

	// assets destroyed in destructor
	virtual ~TreeDemo();

	// update / draw called each frame automaticly
	virtual void Update(float deltaTime);
	virtual void Draw();

protected:

	SpriteBatch *m_spritebatch;
	Tree *m_tree;
	Texture *m_nodeTexture;
	Font* m_font;

private:
};

