#include "Application2D.h"
#include <GLFW/glfw3.h>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"

#include <iostream>
#include <chrono>
#include <algorithm>

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	createWindow("A.I. Project", 1280, 720);

	float x = 1280 / 15;

	float y = 720 / 15;

	m_spriteBatch = new SpriteBatch();

	m_texture = new Texture("./bin/textures/nodeTexture.png");

	crate = new Texture("./bin/textures/crate.png");

	m_font = new Font("./bin/font/consolas.ttf", 32);

	pGraph = new Graph();

	pStart = nullptr;

	pEnd = nullptr;

	timings = 0;

	for (int i = 2; i < 24; ++i)
	{
		for (int j = 2; j < 14; ++j)
		{
			pGraph->AddNode(i*y, j*y);
		}
	}
	
	for (auto const& src : pGraph->nodeList)
		for (auto const&dest : pGraph->nodeList)
			if (src->pos.distance(dest->pos) < 50 && src->pos.distance(dest->pos) > 5)
				pGraph->AddConnection(src, dest);
		

	pPathfinder = nullptr;

	pressed = false;
	
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

	if (isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
	{
		int width, height;
		glfwGetWindowSize(m_window, &width, &height);

		int x, y;
		BaseApplication::getCursorPosition(x, y);
		pStart = pGraph->findNode(Vector2(x,height-y));
	}

	if (isMouseButtonPressed(GLFW_MOUSE_BUTTON_RIGHT))
	{
		int width, height;
		glfwGetWindowSize(m_window, &width, &height);

		int x, y;
		BaseApplication::getCursorPosition(x, y);
		pEnd = pGraph->findNode(Vector2(x, height - y));
	}

	std::chrono::time_point<std::chrono::system_clock> start, end;

	start = std::chrono::system_clock::now();

	if(isKeyPressed(GLFW_KEY_F))
	{
		if (pPathfinder)			
			delete pPathfinder;
						
		pPathfinder = new PathFinder();
		path.erase(path.begin(), path.end());
		pPathfinder->Dijkstras(pStart, pEnd, path);			
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> time = end - start;
		std::cout << time.count() << "\n";
		
	}

	if (isKeyPressed(GLFW_KEY_S))
	{
		pressed = true;

		int x, y;
		getCursorPosition(x, y);
		pGraph->RemoveNodeAt(Vector2(x, 720 - y));
	}
	
	if (isKeyPressed(GLFW_KEY_A) && !pressed)
	{
		pressed = true;

		int x, y;
		getCursorPosition(x, y);
		pGraph->AddNode(x, 720 - y);

		for (auto const& src : pGraph->nodeList)
			for (auto const&dest : pGraph->nodeList)
				if (src->pos.distance(dest->pos) < 100 && src->pos.distance(dest->pos) > 5)
					pGraph->AddConnection(src, dest);
	}
	else if (isKeyPressed(GLFW_KEY_D) && !pressed)
	{
		pressed = true;

		if (pPathfinder)
			delete pPathfinder;

		pPathfinder = new PathFinder();
		path.erase(path.begin(), path.end());
		pPathfinder->AStar(pStart, pEnd, path);
		end = std::chrono::system_clock::now();
		std::chrono::duration<double> time = end - start;
		std::cout << time.count() << "\n";
	}
	else if (pressed && !isKeyPressed(GLFW_KEY_A) && !isKeyPressed(GLFW_KEY_D))
		pressed = false;
		
	timings += (.0000000001*floorf(deltaTime));

	// the applciation closes if we return false
	return true;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();
	

	if (!path.empty())
	{

		//if (timings <= 1 && path.size() == 1)

		if (timings <= 1000 && path.size() > 1)
		{			
			std::list<Graph::Node*>::iterator it = path.begin();
			std::advance(it, 1);			
			Vector2 drawAt = Vector2::lerp(path.front()->pos, (*it)->pos, timings/1000);

			m_spriteBatch->drawSprite(crate, drawAt.x, drawAt.y, 30, 30);
		}
		else if (timings > 1000)
			timings = 0;
			path.pop_front();
	}

	if (pStart != nullptr)
	{
		m_spriteBatch->setSpriteColor(20, 1, 0, 1);
		m_spriteBatch->drawSprite(m_texture, pStart->pos.x, pStart->pos.y, 0, 0, 13);
	}

	if (pEnd != nullptr)
	{
		m_spriteBatch->setSpriteColor(1, 0, 20, 1);
		m_spriteBatch->drawSprite(m_texture, pEnd->pos.x, pEnd->pos.y, 0, 0, 1);
	}

	//if (!path.empty())
	//	for (int i = 0; i < path.size() - 1; ++i)
	//	{
	//		m_spriteBatch->drawLine(path[i]->pos.x, path[i]->pos.y, path[i + 1]->pos.x, path[i + 1]->pos.y);
	//	}

	Graph::Node* current = nullptr;
	Graph::Node* next = nullptr;
	if (!path.empty())
		for (auto &it : path)
		{
			current = it;

			if (next)
				m_spriteBatch->drawLine(current->pos.x, current->pos.y, next->pos.x, next->pos.y);
			next = current;
		}

	m_spriteBatch->setSpriteColor(1, 1, 1, 1);

	for (auto const& it : pGraph->nodeList)
	{
		m_spriteBatch->drawSprite(m_texture, it->pos.x, it->pos.y, 0, 0, 10);

		for (auto const& edges : it->connections)
		{
			m_spriteBatch->drawLine(it->pos.x, it->pos.y, edges.connection->pos.x, edges.connection->pos.y, 1, 12);
		}
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