#pragma once


#include <list>
#include <vector>
#include "BaseApplication.h"
#include "Graph.h"
#include "PathFinder.h"


class SpriteBatch;
class Texture;
class Font;


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
	Texture*		crate;
	Font*			m_font;
	Graph*			pGraph;
	std::list < Graph::Node* > path;
	Graph::Node*	pStart;
	Graph::Node*	pEnd;
	PathFinder*		pPathfinder;
	bool			pressed;
	float			timings;

};