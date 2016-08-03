#pragma once

#include "BaseApplication.h"
#include "Vector3.h"
#include <vector>


class SpriteBatch;
class Texture;
class Font;
class Agent;
class Graph;
class Arrow;
class PathFinder;

class Tree	
{
public:
	Tree(Vector3 pos, float rad)
	{
		position = pos;
		radius = rad;
	}

	Vector3 position;
	float radius;
};

class Application2D : public BaseApplication {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual bool update(float deltaTime);
	virtual void draw();

	std::vector<Agent*> agents;
	std::vector<Arrow*> arrows;
	std::vector<Tree*> trees;

	Graph*			m_graph;
	Texture*		m_arrow;


protected:

	SpriteBatch*	m_spriteBatch;
	Texture*		m_texture;
	Texture*		m_tree;
	Texture*		m_node;
	Texture*		leg;
	
	Font*			m_font;
	




	Agent* mouse;
};