#include "Application2D.h"
#include <GLFW/glfw3.h>
#include <fstream>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Sprite.h"


Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	createWindow("A.I. Project", 1280, 720);

	m_spriteBatch = new SpriteBatch();

	//m_texture = new Texture("./bin/textures/crate.png");

	m_font = new Font("./bin/font/consolas.ttf", 32);

	m_crate = new Sprite();

	m_scene = new Scene();

	m_scene->SetRoot(m_crate);

	pressed = false;

	return true;
}

void Application2D::shutdown() {

	delete m_font;
	//delete m_texture;
	delete m_spriteBatch;

	destroyWindow();
}

bool Application2D::update(float deltaTime) {
	
	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	m_crate->Update(deltaTime);

	m_scene->UpdateTransforms();

	if (isKeyPressed(GLFW_KEY_S) && !pressed)
	{
		pressed = true;
		std::ofstream file("data.dat");
		m_scene->SaveTransforms(file);
		file.close();
	}
	//else if(!isKeyPressed(GLFW_KEY_S) && pressed)
	//	pressed = false;

	if (isKeyPressed(GLFW_KEY_D) && !pressed)
	{
		pressed = true;
		std::ifstream file("data.dat");
		m_scene->LoadTransforms(file);
		file.close();
	}

	if (!isKeyPressed(GLFW_KEY_D) && !isKeyPressed(GLFW_KEY_S) && pressed)
		pressed = false;
	

	// the applciation closes if we return false
	return true;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	//m_spriteBatch->drawSprite(m_texture, 200, 200, 100, 100);

	//m_spriteBatch->drawLine(300, 300, 600, 400, 10, 1);

	//m_spriteBatch->setSpriteColor(1, 0, 0, 1);
	//m_spriteBatch->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f);
	m_crate->Draw(m_spriteBatch);
	

	//m_spriteBatch->setSpriteColor(0, 1, 1, 1);
	m_spriteBatch->drawText(m_font, "Press 's' to save and 'd' to load", 25, 675);
	//m_spriteBatch->drawText(m_font, "Yeaaahhhhh", 200, 300);

	

	// done drawing sprites
	m_spriteBatch->end();	
}