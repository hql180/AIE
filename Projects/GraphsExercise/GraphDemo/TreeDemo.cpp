#include "TreeDemo.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Tree.h"
#include <string>

TreeDemo::TreeDemo(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);

	m_tree = new Tree(10);

	m_tree->insert(30);
	m_tree->insert(20);
	m_tree->insert(10);
	m_tree->insert(5);
	m_tree->insert(4);
		
	/*for (int i = 0; i < 10; ++i)
	{

	}*/

	m_nodeTexture = new Texture("./Images/nodeTexture.png");
	m_font = new Font("./Fonts/arial_20px.fnt");
}

TreeDemo::~TreeDemo()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
	delete m_tree;
}


void TreeDemo::Update(float deltaTime)
{
	if (Input::GetSingleton()->WasMouseButtonPressed(0))
	{
		int mx, my;
		Input::GetSingleton()->GetMouseXY(&mx, &my);

		
	}

	if (Input::GetSingleton()->WasMouseButtonPressed(1))
	{
		int mx, my;
		Input::GetSingleton()->GetMouseXY(&mx, &my);

		
	}
}

void TreeDemo::Draw()
{
	// clear the back buffer
	ClearScreen();

	m_spritebatch->Begin();

	// Draw graph here

	//for (auto & it : m_tree->)
	//	for (std::vector<Graph::Node*>::iterator it = m_graph->m_nodeList.begin(); it != m_graph->m_nodeList.end(); ++it)
	//	{

	//		m_spritebatch->DrawSprite(m_nodeTexture, (*it)->m_data.x, (*it)->m_data.y);

	//		/*for (std::vector<Graph::Edge*>::iterator e = (*it)->m_connections.begin(); e != (*it)->m_connections.end(); ++e)
	//		{
	//		m_spritebatch->DrawLine((*it)->m_data.x, (*it)->m_data.y, (*e)->m_destination->m_data.x, (*e)->m_destination->m_data.y);
	//		}*/

	//		for (auto & element : (*it)->m_connections)
	//		{
	//			m_spritebatch->DrawLine((*it)->m_data.x, (*it)->m_data.y, element.m_destination->m_data.x, element.m_destination->m_data.y);
	//		}

	//	}


	m_spritebatch->End();
}

