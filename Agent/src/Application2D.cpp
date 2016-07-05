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


Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	createWindow("A.I. Project", 1280, 720);

	m_spriteBatch = new SpriteBatch();

	m_texture = new Texture("./bin/textures/red.png");

	m_font = new Font("./bin/font/consolas.ttf", 32);

	for (int i = 0; i < 10; ++i)
		agents.push_back(new Agent(m_texture));

	std::mt19937 gen;
	std::uniform_int_distribution<int> dis(0, 9);

	srand(time(NULL));
	int counter = 0;
	for (auto & it : agents)
	{
		it->behaviourList.push_back(new Wander());
		it->behaviourList.push_back(new Flee());
		it->behaviourList.push_back(new Seek());
		if (counter + 1 < 10)
			it->target = agents[counter + 1];	
		//if (9 - counter % 2 == 0)
		//	it->fleeTarget = agents[9 - counter];
/*		if (counter + 1 < 10)
			it->fleeTarget = agents[counter + 1];
		else
			it->fleeTarget = agents[0];		
		++counter;	*/	
		/*it->target = agents[dis(gen)];
		it->fleeTarget = agents[dis(gen)];*/
	}
	agents[9]->target = agents[0];

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
		it->update(deltaTime);

	//if (BaseApplication::isKeyPressed(GLFW_KEY_S))
	
	int x, y;

	BaseApplication::getCursorPosition(x, y);

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