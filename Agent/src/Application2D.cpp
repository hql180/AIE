#include "Application2D.h"
#include <GLFW/glfw3.h>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "MathLib.h"
#include "Agent.h"
#include "IBehaviour.h"
#include "Wander.h"
#include <time.h>
#include "Seek.h"


Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	createWindow("A.I. Project", 1280, 720);

	m_spriteBatch = new SpriteBatch();

	m_texture = new Texture("./bin/textures/crate.png");

	m_font = new Font("./bin/font/consolas.ttf", 32);

	testAgent = new Agent(m_texture);
	testAgent1 = new Agent(m_texture);
	testAgent2 = new Agent(m_texture);
	testAgent3 = new Agent(m_texture);
	testAgent4 = new Agent(m_texture);
	testAgent5 = new Agent(m_texture);
	testAgent6 = new Agent(m_texture);

	testAgent->behaviourList.push_back(new Wander());

	testAgent->target = new Agent();


	testAgent1->behaviourList.push_back(new Wander());
	testAgent2->behaviourList.push_back(new Wander());
	testAgent3->behaviourList.push_back(new Wander());
	testAgent4->behaviourList.push_back(new Wander());
	testAgent5->behaviourList.push_back(new Wander());
	testAgent6->behaviourList.push_back(new Wander());

	srand(time(NULL));

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

	testAgent->update(deltaTime);

	//testAgent1->update(deltaTime);
	//testAgent2->update(deltaTime);
	//testAgent3->update(deltaTime);
	//testAgent4->update(deltaTime);
	//testAgent5->update(deltaTime);
	//testAgent6->update(deltaTime);

	//if (BaseApplication::isKeyPressed(GLFW_KEY_S))
	
	int x, y;

	BaseApplication::getCursorPosition(x, y);

	//testAgent->target->position = Vector3(x, 720 - y, 1);
	
	// the applciation closes if we return false
	return true;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	testAgent->draw(m_spriteBatch);
	/*testAgent1->draw(m_spriteBatch);
	testAgent2->draw(m_spriteBatch);
	testAgent3->draw(m_spriteBatch);
	testAgent4->draw(m_spriteBatch);
	testAgent5->draw(m_spriteBatch);
	testAgent6->draw(m_spriteBatch);*/

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