#include "Application2D.h"
#include <GLFW/glfw3.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <time.h>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	createWindow("A.I. Project", 1280, 720);

	m_spriteBatch = new SpriteBatch();

	m_texture = new Texture("./bin/textures/crate.png");

	m_font = new Font("./bin/font/consolas.ttf", 32);

	m_time = 0;

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

	m_time += deltaTime;

	// the applciation closes if we return false
	return true;
}

float square(float x)
{
	return x*x;
}

float root(float x)
{
	if (x > 0)
		return sqrt(x);
}

float triangle(float x)
{
	return std::max(1.f - std::abs(x / 0.5f - 1), 0.0f);
}

float bounce(float x)
{
	return fabsf(cos(x*10)) * (1-x);
}


void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	int width, height;

	glfwGetWindowSize(m_window, &width, &height);

	int mx = width / 2;
	int my = height / 2;

	m_spriteBatch->drawLine(mx, 0, mx, height);

	m_spriteBatch->drawLine(0, my, width, my);

	
	float crateTime = m_time - floorf(m_time);
	

	m_spriteBatch->drawSprite(m_texture, crateTime*mx + mx, bounce(mx*crateTime)+height, 20, 20, 1 - crateTime);

	/*for (int i = -100; i < 100; ++i)
	{
		m_spriteBatch->drawSprite(m_texture, i, 500, 50, 50, 1);
	}*/

	m_spriteBatch->drawFunction(bounce, mx, my);

	// done drawing sprites
	m_spriteBatch->end();	
}

