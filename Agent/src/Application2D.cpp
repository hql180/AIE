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
#include "LineOfSight.h"



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

	m_arrow = new Texture("./bin/textures/arrow.png");

	leg = new Texture("./bin/textures/girl.png");

	m_graph = new Graph();

	srand(time(NULL));	

	//for (int i = 0; i < 15; ++i)
	//	agents.push_back(new Agent(m_texture));


	for (int i = 2; i < 52; ++i)
		for (int j = 2; j < 29; ++j)
			m_graph->AddNode(i*blocks, j*blocks); // Adding Path Nodes

	for (auto & src : m_graph->nodeList)
		for (auto & dest : m_graph->nodeList)
			if (src->pos.distance(dest->pos) <= 34)
				if (src != dest)
					m_graph->AddConnection(src, dest);	// Connecting Path Nodes

	std::mt19937 gen;
	std::uniform_int_distribution<int> dis(0, 9);

	std::uniform_int_distribution<int> disX(50, 1230);

	std::uniform_int_distribution<int> disY(50, 670);

	std::uniform_int_distribution<int> treeSize(30, 75);

	arrows.reserve(1000);

	for (int i = 0; i < 50; ++i)
		trees.push_back(new Tree(Vector3(disX(gen), disY(gen), 0), treeSize(gen))); // Adding Random Trees

	for (auto & tree : trees)
		m_graph->RemoveNodeAt(Vector2(tree->position.x, tree->position.y), tree->radius*(3/4.f)); // Removing Nodes around radius of tree

	///////////////// BEHAVIOUR TREE ///////////////////////
	
	Selector* fightOrWander = new Selector(); // Fight or Wander 0/3

	Selector* fightOrFlight = new Selector(); // Fight or Flight 0/2

	fightOrWander->childBehaviours.push_back(new IsDead()); // Fight or Wander 1/3

	fightOrWander->childBehaviours.push_back(fightOrFlight); // Fight or Wander 2/3

	Sequence* runAway = new Sequence(); // Run Away 0/3

	fightOrFlight->childBehaviours.push_back(runAway); // Fight or Flight 1/2

	runAway->childBehaviours.push_back(new InCombat());	// Run Away 1/3
	runAway->childBehaviours.push_back(new LowHealth()); // Run Away 2/3
	runAway->childBehaviours.push_back(new EvadePath()); // Run Away 3/3
	runAway->childBehaviours.push_back(new Heal());
	runAway->childBehaviours.push_back(new SeekPath()); // RunAway 4

	Sequence* goodFightingCondition = new Sequence(); // Good Fighting Condition 0/2

	fightOrFlight->childBehaviours.push_back(goodFightingCondition); // Fight or Flight 2/2	

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
	attack->childBehaviours.push_back(new LineOfSight());
	attack->childBehaviours.push_back(new Attack()); // ATTACK 2/2

	attackOrClose->childBehaviours.push_back(new SeekPath()); // Attack or seek 2/2

	targetOrPath->childBehaviours.push_back(new SeekPath()); // Target or Path 2/2

	Selector* wanderOrHeal = new Selector(); // Wander or Heal 0/2

	fightOrWander->childBehaviours.push_back(wanderOrHeal); // Fight or Wander 3/3

	//Sequence* heal = new Sequence(); // Heal 0/2

	//wanderOrHeal->childBehaviours.push_back(heal);

	//Decorator * notInCombat = new Decorator();

	//notInCombat->childBehaviours.push_back(new InCombat());

	//heal->childBehaviours.push_back(new Heal());

	//heal->childBehaviours.push_back(new EvadePath());

	//heal->childBehaviours.push_back(new SeekPath());	

	Sequence* wander = new Sequence();

	wanderOrHeal->childBehaviours.push_back(wander); // Wander or Heal 0/2

	wander->childBehaviours.push_back(new WanderPath());
	wander->childBehaviours.push_back(new Heal());
	wander->childBehaviours.push_back(new SeekPath());

	///////////////////// END OF TREE ////////////////////////////////////////

	//Sequence* fightOrWander = new Sequence();

	//fightOrWander->childBehaviours.push_back(new EvadePath());
	//fightOrWander->childBehaviours.push_back(new SeekPath());

	//Sequence* seekTarget = new Sequence();
	//seekTarget->childBehaviours.push_back(new SelectTarget());
	//seekTarget->childBehaviours.push_back(new AddPath());
	//seekTarget->childBehaviours.push_back(new SeekPath());




	for (int i = 0; i < 20; ++i)
	{
		agents.push_back(new Archer(m_texture, Vector3(disX(gen), disY(gen), 1))); // Adding bunch of archers
		agents.back()->behaviourList.push_back(fightOrWander);
	}

	//agents.push_back(new Archer(m_texture, Vector3( 600, 340, 1)));
	//agents.back()->behaviourList.push_back(fightOrWander);

	Archer* Legolas = new Archer(leg, Vector3(550, 320, 1), 100, 150, 10, .15, 450, 600, 2.5); // Adding most likey winner of simulation
	Legolas->behaviourList.push_back(fightOrWander);
	
	agents.push_back(Legolas);

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

	// Delete dead agents and clean up any pointers;
	for (auto agent : agents)
	{
		if (agent->isDead)
		{
			// Clear any targets on arrows for this agent
			for (auto arrow : arrows)
			{
				if (arrow->target == agent)
				{
					arrow->target = nullptr;
				}
			}
		}
	}

	agents.erase(std::remove_if(agents.begin(), agents.end(), [](Agent* a) 
	{
		if (a->isDead)
		{
			delete a;
			return true;
		}
		return false;
	}), agents.end());

	for (auto it : agents)
	{
		it->update(this, deltaTime);
	}

	for (int i = 0; i < arrows.size(); ++i)
		arrows[i]->update(this, deltaTime);

	arrows.erase(std::remove_if(arrows.begin(), arrows.end(), [](Arrow* a) 
	{
		if (a->isDead)
		{
			delete a;
			return true;
		}
		return false;
	}), arrows.end());


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