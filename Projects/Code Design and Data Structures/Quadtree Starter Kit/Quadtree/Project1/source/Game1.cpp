/*-----------------------------------------------------------------------------
Author:			Richard Stern, based on code by Elizabeth Rowlands			
Description:	Finite State machine
-----------------------------------------------------------------------------*/

#include "Game1.h"

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Enemy.h"
#include "HelperFunctions.h"

#include <list>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <set>

// Used to arrange enemies in a square grid that fills most of the screen
#define SCREEN_PADDING_X 200
#define SCREEN_PADDING_Y 200
#define ENEMY_SPACING 100

float Game1::checkcount = 0;

std::vector<Enemy*> list;

Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char * title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_nFramesPassed = 0;
	m_fTimePassed = 0.0f;
	m_fFPS = 0.0f;
	quadMode = false;


	SetVSync(false);
	srand((unsigned int)time(nullptr));

	// Creating the sprite batch
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);

	// Load in the textures that we want to use
	m_backgroundTexture = new Texture("./Images/background.png");
	m_mouseTexture = new Texture("./Images/Player.png");

	// Create the font for use with draw string
	m_font = new Font("./Fonts/calibri_24px.fnt");

	// Defaults for mouse X and Y
	m_v2MousePos.x = 0.0f;
	m_v2MousePos.y = 0.0f;
	m_fMouseRadius = 100.0f;

	Vector2 v2LevelTopLeft;
	v2LevelTopLeft.x = 0.0f;
	v2LevelTopLeft.y = 0.0f;
	Vector2 v2LevelBottomRight;
	v2LevelBottomRight.x = (float)windowWidth;
	v2LevelBottomRight.y = (float)windowHeight;

	quadtree = QuadTree(v2LevelTopLeft, v2LevelBottomRight);


	// Spawn a grid of slightly randomly placed enemies.
	// First calculate how many enemies we can fit on the screen.
	m_MaxEnemiesPerRow = (windowWidth - SCREEN_PADDING_X) / ENEMY_SPACING;
	m_MaxEnemiesPerColumn = (windowHeight - SCREEN_PADDING_Y) / ENEMY_SPACING;
	m_EnemyCount = m_MaxEnemiesPerRow * m_MaxEnemiesPerColumn;

	// Create the enemies
	m_apEnemyList = new Enemy*[m_MaxEnemiesPerRow * m_MaxEnemiesPerColumn];
	for (int x = 0; x < m_MaxEnemiesPerRow; ++x)
	{
		for (int y = 0; y < m_MaxEnemiesPerColumn; ++y)
		{
			int index = (y * m_MaxEnemiesPerRow) + x;
			float posX = (float)SCREEN_PADDING_X + (x * ENEMY_SPACING);
			float posY = (float)SCREEN_PADDING_Y + (y * ENEMY_SPACING);

			posX += -ENEMY_SPACING + rand() % (ENEMY_SPACING * 2);
			posY += -(ENEMY_SPACING / 2) + rand() % (ENEMY_SPACING);

			m_apEnemyList[index] = new Enemy(posX, posY);

			quadtree.root.AddEnemy(m_apEnemyList[index]);
			}
	}
}

Game1::~Game1()
{
	// DELETE EVERYTHING!!!
	for(int i = 0; i < m_EnemyCount; ++i)
	{
		delete m_apEnemyList[i];
	}
	delete m_apEnemyList;

	SpriteBatch::Factory::Destroy(m_spritebatch);

	delete m_backgroundTexture;
	delete m_mouseTexture;

	delete m_font;
}

void Game1::Update(float deltaTime)
{
	// Calculate FPS
	m_fTimePassed += deltaTime;
	m_nFramesPassed++;
	if(m_fTimePassed > 0.25f && m_nFramesPassed > 5)
	{
		m_fFPS = ((float)m_nFramesPassed / m_fTimePassed);
		m_fTimePassed = 0.0f;
		m_nFramesPassed = 0;
	}

	checkcount = list.size();

	// Get the mouse X and Y position
	int mouseX;
	int mouseY;
	Input::GetSingleton()->GetMouseXY(&mouseX, &mouseY);
	m_v2MousePos.x = (float)mouseX;
	m_v2MousePos.y = (float)mouseY;

	if (Input::GetSingleton()->WasKeyPressed(81))
	{
		if (!quadMode)
			quadMode = true;
		else
			quadMode = false;
	}
	
	// Update all the enemies
	UpdateEnemies(deltaTime);
}

void Game1::DrawQuadTree(QuadTree::Node* node)
{
	DrawSquare(m_spritebatch, node->tLeft, node->bRight);
	if (node->quad[0])
	{
		for (int i = 0; i < 4; i++)
		{
			DrawQuadTree(node->quad[i]);
		}		
	}
}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();
	
	m_spritebatch->Begin();

	
	// Draw the background
	m_spritebatch->DrawSprite(m_backgroundTexture, SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, SCREEN_WIDTH, SCREEN_HEIGHT);

	// Draw mouse texture
	m_spritebatch->DrawSprite(m_mouseTexture, m_v2MousePos.x, m_v2MousePos.y);


	DrawQuadTree(&quadtree.root);

	// Draw info text
	char buffer[512];
	sprintf_s(buffer, 512, "Enemies within range of the mouse turn red.\nThis is linearly checking the distance to every enemy which is slow!\n(The distance check has been artificially slowed down in this project to make this even more obvious)\nA Quadtree would reduce the number of distance checks and would make this a lot faster.\nFPS: %.2f", m_fFPS);
	m_spritebatch->DrawString(m_font, buffer, 50, 30);

	char checks[512];

	sprintf_s(checks, 512, "Press 'Q' to toggle between modes\nChecks performed: %f", checkcount);
	m_spritebatch->DrawString(m_font, checks, 50, 150);
	

	// Draw enemies
	for(int i = 0; i < m_EnemyCount; ++i)
	{
		m_apEnemyList[i]->Draw(m_spritebatch);
	}

	

	m_spritebatch->End();
}

// Update all the enemies so they become aggresive if the mouse cursor is within a certain distance of them.
// Change them back to normal once the mouse leaves that area
void Game1::UpdateEnemies(float deltatime)
{
	//Reset all enemies
	for (int i = 0; i < m_EnemyCount; ++i)
	{
		m_apEnemyList[i]->SetAngry(false);
	}

	if (!quadMode)
	{
		//Linear trawl through all the enemies in the level to check if they are close to the mouse
		//If so make them angry. This is slow!
		for (int i = 0; i < m_EnemyCount; ++i)
		{
			float fDist = Vector2::GetDistance(m_apEnemyList[i]->GetPos(), m_v2MousePos);
			if (fDist < m_fMouseRadius)
				m_apEnemyList[i]->SetAngry(true);
		}
		std::cout << m_EnemyCount<<'\n';
	}

	//Use Quadtree here instead to find enemies that are roughly nearby and then do the distance check just on those ones to confirm.
	
	//<BEGIN PSEUDOCODE>
	//enemyList = QuadTree.Get(mousePos, m_fMouseRadius);
	//LOOP through enemies in enemyList
		//float fDist = Vector2::GetDistance(m_apEnemyList[i]->GetPos(), m_v2MousePos);
		//if(fDist < m_fMouseRadius)
			//m_apEnemyList[i]->SetAngry(true);
	//END LOOP

	if (quadMode)
	{
		
		list.erase(list.begin(), list.end());
		quadtree.root.Get(m_v2MousePos, list);

		/*std::set<Enemy*> set(list.begin(), list.end());
		list.assign(set.begin(), set.end());*/

		std::cout << list.size() << "\n";


		checkcount = list.size();

		for (int i = 0; i < list.size(); ++i)
		{
			float fDist = Vector2::GetDistance(list[i]->GetPos(), m_v2MousePos);
			if (fDist < m_fMouseRadius)
				list[i]->SetAngry(true);
		}
	}

	//<END PSEUDOCODE>
}

