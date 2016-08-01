#include "Application2D.h"
#include <GLFW/glfw3.h>
#include <time.h>
#include <random>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "MathLib.h"
#include "Agent.h"
#include "IBehaviour.h"
#include "Wander.h"
#include "Seek.h"
#include "Flee.h"
#include "Pursue.h"
#include "Evade.h"
#include "PathFinder.h"
#include "Graph.h"


Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	createWindow("A.I. Project", 1280, 720);

	float blocks = 720 / 30;

	m_spriteBatch = new SpriteBatch();

	m_texture = new Texture("./bin/textures/red.png");

	m_tree = new Texture("./bin/textures/bush.png");

	m_node = new Texture("./bin/textures/nodeTexture.png");

	m_font = new Font("./bin/font/consolas.ttf", 32);

	m_graph = new Graph();

	for (int i = 0; i < 15; ++i)
		agents.push_back(new Agent(m_texture));



	for (int i = 2; i < 52; ++i)
		for (int j = 2; j < 29; ++j)
			m_graph->AddNode(i*blocks, j*blocks);

	for (auto & src : m_graph->nodeList)
		for (auto & dest : m_graph->nodeList)
			if (src->pos.distance(dest->pos) <= 34)
				if (src != dest)
					m_graph->AddConnection(src, dest);

	std::mt19937 gen;
	std::uniform_int_distribution<int> dis(0, 9);

	trees.push_back(new Tree(Vector3(300, 300, 0), 50));
	
	srand(time(NULL));
	int counter = 0;
	for (auto & it : agents)
	{
		it->behaviourList.push_back(new Wander());
		it->behaviourList.push_back(new Evade());
		it->behaviourList.push_back(new Pursue());
		if (counter + 1 < 10)
			it->target = agents[counter + 1];	
		if (9 - counter % 2 == 0)
			it->fleeTarget = agents[9 - counter];
		//if (counter + 1 < 10)
		//	it->fleeTarget = agents[counter + 1];
		//else
		//	it->fleeTarget = agents[0];		
		++counter;		
		/*it->target = agents[dis(gen)];
		it->fleeTarget = agents[dis(gen)];*/
	}

	mouse = new Agent(m_texture);

	agents[9]->target = mouse;

	


	return true;
}

void Application2D::shutdown() {

	delete m_font;
	delete m_texture;
	delete m_spriteBatch;

	destroyWindow();
}

bool Application2D::update(float deltaTime) {
	
	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	for (auto & it : agents)
		it->update(this, deltaTime);

	//if (BaseApplication::isKeyPressed(GLFW_KEY_S))
	
	int x, y;

	BaseApplication::getCursorPosition(x, y);

	mouse->position = Vector3(x, 720 - y, 1);



	//agents[5]->target->position = Vector3(x, 720-y, 1);

	//testAgent->target->position = Vector3(x, 720 - y, 1);
	
	// the applciation closes if we return false
	return true;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	for (auto & it : agents)
		it->draw(m_spriteBatch);

	

	for (auto graph : m_graph->nodeList)
	{
		m_spriteBatch->drawSprite(m_node, graph->pos.x, graph->pos.y, 0, 0, 10);

		for(auto & edges: graph->connections)
			m_spriteBatch->drawLine(graph->pos.x, graph->pos.y, edges.connection->pos.x, edges.connection->pos.y, 1, 12);
	}


	m_spriteBatch->drawSprite(m_tree, trees[0]->position.x, trees[0]->position.y, trees[0]->radius, trees[0]->radius);
	/*m_spriteBatch->drawSprite(m_texture, 200, 200, 100, 100);

	m_spriteBatch->drawLine(300, 300, 600, 400, 10, 1);

	m_spriteBatch->setSpriteColor(1, 0, 0, 1);
	m_spriteBatch->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f);

	m_spriteBatch->setSpriteColor(0, 1, 1, 1);
	m_spriteBatch->drawText(m_font, "OMG BBQ!", 200, 400);
	m_spriteBatch->drawText(m_font, "Yeaaahhhhh", 200, 300);*/

	// done drawing sprites
	m_spriteBatch->end();	
}