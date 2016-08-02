#include "Application2D.h"
#include <GLFW/glfw3.h>
#include <time.h>
#include <random>
#include <algorithm>

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
#include "Selector.h"
#include "Sequence.h"
#include "InCombat.h"
#include "LowHealth.h"
#include "Decorator.h"
#include "SelectTarget.h"
#include "InRange.h"
#include "Arrow.h"
#include "Attack.h"
#include "IsDead.h"
#include "SeekPath.h"
#include "Heal.h"
#include "WanderPath.h"
#include "Archer.h"
#include "AddPath.h"
#include "EvadePath.h"



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

	m_arrow = new Texture("./bin/textures/nodeTexture.png");

	m_graph = new Graph();

	srand(time(NULL));	

	//for (int i = 0; i < 15; ++i)
	//	agents.push_back(new Agent(m_texture));


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

	std::uniform_int_distribution<int> disX(50, 1230);

	std::uniform_int_distribution<int> disY(50, 670);

	std::uniform_int_distribution<int> treeSize(30, 75);

	for (int i = 0; i < 50; ++i)
		trees.push_back(new Tree(Vector3(disX(gen), disY(gen), 0), treeSize(gen)));

	for (auto & tree : trees)
		m_graph->RemoveNodeAt(Vector2(tree->position.x, tree->position.y), tree->radius/2);

	Selector* fightOrWander = new Selector(); // Fight or Wander 0/3

	Selector* fightOrFlight = new Selector(); // Fight or Flight 0/2

	fightOrWander->childBehaviours.push_back(new IsDead()); // Fight or Wander 1/3

	fightOrWander->childBehaviours.push_back(fightOrFlight); // Fight or Wander 2/3

	Sequence* runAway = new Sequence(); // Run Away 0/3

	fightOrFlight->childBehaviours.push_back(runAway); // Fight or Flight 1/2

	runAway->childBehaviours.push_back(new InCombat());	// Run Away 1/3
	runAway->childBehaviours.push_back(new LowHealth()); // Run Away 2/3
	runAway->childBehaviours.push_back(new EvadePath()); // Run Away 3/3
	runAway->childBehaviours.push_back(new SeekPath()); // RunAway 4

	Sequence* goodFightingCondition = new Sequence(); // Good Fighting Condition 0/2

	fightOrFlight->childBehaviours.push_back(goodFightingCondition); // Fight or Flight 2/2

	Decorator* notLowHealth = new Decorator(); // Not LowHealth 0/1

	goodFightingCondition->childBehaviours.push_back(notLowHealth); // Good Fighting Condition 1/2

	notLowHealth->childBehaviours.push_back(new LowHealth());  // Not LowHealth 0/1

	Selector* targetOrPath = new Selector(); // Target or Path 0/2

	goodFightingCondition->childBehaviours.push_back(targetOrPath); // Good Fighting Condition 2/2

	Sequence* targetInSight = new Sequence(); // Target in Sight 0/2

	targetOrPath->childBehaviours.push_back(targetInSight); // Target or Path 1/2

	targetInSight->childBehaviours.push_back(new SelectTarget()); // Target in Sight 1/2

	targetInSight->childBehaviours.push_back(new AddPath());

	Selector* attackOrClose = new Selector(); // Attack or seek 0/2

	targetInSight->childBehaviours.push_back(attackOrClose); // Target in Sight 2/2

	Sequence* attack = new Sequence(); // ATTACK 0/2

	attackOrClose->childBehaviours.push_back(attack); // Attack or seek 1/2

	attack->childBehaviours.push_back(new InRange()); // ATTACK 1/2
	attack->childBehaviours.push_back(new Attack()); // ATTACK 2/2

	attackOrClose->childBehaviours.push_back(new SeekPath()); // Attack or seek 2/2

	targetOrPath->childBehaviours.push_back(new SeekPath()); // Target or Path 2/2

	Selector* wanderOrHeal = new Selector(); // Wander or Heal 0/2

	fightOrWander->childBehaviours.push_back(wanderOrHeal); // Fight or Wander 3/3

	Sequence* heal = new Sequence(); // Heal 0/2

	wanderOrHeal->childBehaviours.push_back(new Heal()); // Wander or Heal 0/2

	wanderOrHeal->childBehaviours.push_back(new WanderPath()); // Wander or Heal 0/2

	for (int i = 0; i < 10; ++i)
	{
		agents.push_back(new Archer(m_texture, Vector3(disX(gen), disY(gen), 1)));
		agents.back()->behaviourList.push_back(fightOrWander);
	}

	
	
	//int counter = 0;
	//for (auto & it : agents)
	//{
	//	it->behaviourList.push_back(new Wander());
	//	it->behaviourList.push_back(new Evade());
	//	it->behaviourList.push_back(new Pursue());
	//	if (counter + 1 < 10)
	//		it->target = agents[counter + 1];	
	//	if (9 - counter % 2 == 0)
	//		it->fleeTarget = agents[9 - counter];
	//	//if (counter + 1 < 10)
	//	//	it->fleeTarget = agents[counter + 1];
	//	//else
	//	//	it->fleeTarget = agents[0];		
	//	++counter;		
	//	/*it->target = agents[dis(gen)];
	//	it->fleeTarget = agents[dis(gen)];*/
	//}

	//mouse = new Agent(m_texture);

	//agents[9]->target = mouse;

		


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

	//std::remove_if(arrows.begin(), arrows.end(), [](Arrow* a) {return a->isDead;});

	//for (int i = 0; i < arrows.size(); ++i)
	//	arrows[i]->update(this, deltaTime);

	//if (BaseApplication::isKeyPressed(GLFW_KEY_S))
	
	//int x, y;

	//BaseApplication::getCursorPosition(x, y);

	//mouse->position = Vector3(x, 720 - y, 1);



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

	

	for (auto& arrow : arrows)
		if (arrow->isDead == false)
			arrow->draw(m_spriteBatch);
	

	//for (auto graph : m_graph->nodeList)
	//{
	//	m_spriteBatch->drawSprite(m_node, graph->pos.x, graph->pos.y, 0, 0, 10);

	//	for(auto & edges: graph->connections)
	//		m_spriteBatch->drawLine(graph->pos.x, graph->pos.y, edges.connection->pos.x, edges.connection->pos.y, 1, 12);
	//}

	
	for (auto tree : trees)
	{
		//m_spriteBatch->drawSprite(m_node, tree->position.x, tree->position.y, 10, 10);
		m_spriteBatch->drawSprite(m_tree, tree->position.x, tree->position.y, tree->radius, tree->radius);
		
	}

	

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