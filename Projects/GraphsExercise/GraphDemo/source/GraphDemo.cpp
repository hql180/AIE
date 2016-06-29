#include "GraphDemo.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Graph.h"
#include <string>

GraphDemo::GraphDemo(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);	

	m_graph = new Graph(); 
	Graph::Node *a = m_graph->AddNode(Vector2(100, 100)); 
	
	float graphScale = 2.5f;
	Graph::Node *b = m_graph->AddNode(Vector2(150 * graphScale, 100 * graphScale));
	Graph::Node *c = m_graph->AddNode(Vector2(200 * graphScale, 100 * graphScale));
	Graph::Node *d = m_graph->AddNode(Vector2(150 * graphScale, 150 * graphScale));
	Graph::Node *e = m_graph->AddNode(Vector2(100 * graphScale, 200 * graphScale));
	Graph::Node *f = m_graph->AddNode(Vector2(150 * graphScale, 200 * graphScale));
	Graph::Node *g = m_graph->AddNode(Vector2(200 * graphScale, 200 * graphScale));
	Graph::Node *h = m_graph->AddNode(Vector2(300 * graphScale, 150 * graphScale));
	Graph::Node *i = m_graph->AddNode(Vector2(250 * graphScale, 100 * graphScale));
	Graph::Node *j = m_graph->AddNode(Vector2(300 * graphScale, 100 * graphScale));
	Graph::Node *k = m_graph->AddNode(Vector2(350 * graphScale, 100 * graphScale));

	m_graph->ConnectNodes(a, d, 1);
	m_graph->ConnectNodes(d, b, 1); 
	m_graph->ConnectNodes(d, c, 1); 
	m_graph->ConnectNodes(d, h, 1); 
	m_graph->ConnectNodes(d, e, 1); 
	m_graph->ConnectNodes(d, f, 1); 
	m_graph->ConnectNodes(d, g, 1); 
	m_graph->ConnectNodes(h, i, 1); 
	m_graph->ConnectNodes(h, j, 1); 
	m_graph->ConnectNodes(h, k, 1);

	m_graph->ConnectNodes(h, g, 1);
	m_graph->ConnectNodes(g, d, 1);

	m_nodeTexture = new Texture("./Images/nodeTexture.png");
	m_font = new Font("./Fonts/arial_20px.fnt");
}

GraphDemo::~GraphDemo()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
	delete m_graph;
}


void GraphDemo::Update(float deltaTime)
{
	if (Input::GetSingleton()->WasMouseButtonPressed(0))
	{
		int mx, my;
		Input::GetSingleton()->GetMouseXY(&mx, &my);
		
		Vector2 temp(mx, my);

		m_graph->AddNode(temp);

		for (auto & it : m_graph->m_nodeList)
		{
			int a = it->m_data.x - mx;
			int b = it->m_data.y - my;
			a *= a;
			b *= b;
			if (a + b < 100 * 100)
			{
				m_graph->ConnectNodes(m_graph->FindNode(temp), it, 100);
			}
		}
	}

	if (Input::GetSingleton()->WasMouseButtonPressed(1))
	{
		int mx, my;
		Input::GetSingleton()->GetMouseXY(&mx, &my);

		Vector2 temp(mx, my);

		m_graph->RemoveNode(m_graph->FindNode(temp));
	}
}

void GraphDemo::Draw()
{
	// clear the back buffer
	ClearScreen();

	m_spritebatch->Begin();

	// Draw graph here
	//m_spritebatch->setSpriteColor(3, 250, 20, 10);

	for (std::vector<Graph::Node*>::iterator it = m_graph->m_nodeList.begin(); it != m_graph->m_nodeList.end(); ++it)
	{
		
		m_spritebatch->DrawSprite(m_nodeTexture, (*it)->m_data.x, (*it)->m_data.y);

		/*for (std::vector<Graph::Edge*>::iterator e = (*it)->m_connections.begin(); e != (*it)->m_connections.end(); ++e)
		{
			m_spritebatch->DrawLine((*it)->m_data.x, (*it)->m_data.y, (*e)->m_destination->m_data.x, (*e)->m_destination->m_data.y);
		}*/
		
		for (auto & element : (*it)->m_connections)
		{
			m_spritebatch->DrawLine((*it)->m_data.x, (*it)->m_data.y, element.m_destination->m_data.x, element.m_destination->m_data.y);			
		}
		
	}
	
	
	m_spritebatch->End();
}

