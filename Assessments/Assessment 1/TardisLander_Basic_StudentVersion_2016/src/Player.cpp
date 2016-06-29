#include <GLFW/glfw3.h>
#include "Player.h"
#include "GameDefs.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Matrix3.h"
#include "Vector2.h"
#include "Application2D.h"
#include "Sprite.h"


Player::Player()
{
	m_sprite = new Texture("./bin/textures/ship.png");
	m_pFireSprite = new Sprite("./bin/textures/fire.png");
	AddChild(m_pFireSprite);
	m_pFireSprite->SetLocalTransform(Matrix3::CreateTranslation(Vector3(0, -110, 1)));
	
	Reset();
}

Player::~Player(void)
{
	delete m_sprite;
	delete m_pFireSprite;
}

void Player::Reset() {
	local_transform = Matrix3::CreateTranslation(HALF_SCRW, HALF_SCRH);
	m_velocity.m_x = 0;
	m_velocity.m_y = 0; // was 1
	m_gravity = Matrix3::CreateIdentity();
	m_gravity.m[2][1] = 1;
	m_gravity.Transpose();
	m_rotation = 0.0;
	m_bIsDead = false;
	m_bHasLanded = false;
	m_bFlameOn = false;
}

void Player::Update(float dt) {
	if(m_bHasLanded)
		return;

	//drop ship due to gravity
	m_velocity.m_y -= GRAVITY;
	

	Application2D* app = Application2D::getInstance();
	
	//turn ship left or right
	if(app->IsKeyDown(GLFW_KEY_LEFT))
		m_rotation += 0.1;
	if(app->IsKeyDown(GLFW_KEY_RIGHT))
		m_rotation -= 0.1;

	 //calculate thrust according to current rotation
	if(app->IsKeyDown(GLFW_KEY_UP)) {
		m_bFlameOn = true;
		m_velocity.m_y += SPEED; 
	}
	else {
		m_bFlameOn = false;
	}

	Matrix3 mR = Matrix3::CreateRotation(m_rotation * (M_PI / 180));
	Matrix3 mT = Matrix3::CreateTranslation(m_velocity.m_x*dt, m_velocity.m_y*dt);

	local_transform = mR * mT * local_transform + m_gravity;

	if (local_transform.m[2][1] - PLAYER_HALFH < GROUND_Y ) {
		float speed = m_velocity.magnitude() * dt;
		if (speed > 0.5f) {
			// CRASH!!!
			m_bIsDead = true;
		}
		m_bHasLanded = true;
		m_velocity.m_y = 0;
		m_velocity.m_x = 0;
	}

	
}

void Player::Draw(SpriteBatch* spritebatch) {	
	/*Matrix3 transpose = Matrix3::CreateTranslation(Vector3(m_position.m_x, m_position.m_y, 0));
	Matrix3 rotation = Matrix3::CreateRotation(m_rotation * (M_PI / 180));
	Matrix3 translation = rotation * transpose;*/



	spritebatch->drawSpriteTransformed3x3(m_sprite, (float*)global_transform.m);

	if (m_bFlameOn) {
		//Matrix3 transpose = Matrix3::CreateTranslation(Vector3(m_position.m_x, m_position.m_y, 0));
		//Matrix3 offset = Matrix3::CreateTranslation(Vector3(0, -110, 1));	//can be thought of as displacement from ship
		//Matrix3 rotation = Matrix3::CreateRotation(m_rotation * (M_PI / 180));
		//Matrix3 translation = offset * rotation * transpose;
		//spritebatch->drawSpriteTransformed3x3(m_pFireSprite, (float*)translation.m);

		m_pFireSprite->Draw(spritebatch);
	}
}
