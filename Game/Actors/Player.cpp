#include "Player.h"
#include "Projectile.h"
#include "Object/Scene.h"
#include "Math/Math.h"
#include <fstream>
#include "Math/Vector2.h"



bool Player::Load(const std::string& filename)
{
	bool success = false;
	std::ifstream stream(filename);

	if (stream.is_open())
	{
		success = true;

		// load the base actor members            
		Actor::Load(stream);

		stream >> m_thrust;
		stream >> m_rotationRate;

		stream.close();
	}

	return success;
	
}

void Player::Update(float dt)
{
	m_fireTimer += dt;
	if (Core::Input::IsPressed(VK_SPACE) && m_fireTimer >= m_fireRate)
	{
		m_fireTimer = 0;
		Projectile* projectile = new Projectile;
		projectile->Load("projectile.txt");
		projectile->GetTransform().position = m_transform.position;
		projectile->GetTransform().angle = m_transform.angle;
		m_scene->AddActor(projectile);
	}

	nc::Vector2 force;
	if (Core::Input::IsPressed('W')) { force = nc::Vector2::forward * m_thrust; }
	force = nc::Vector2::Rotate(force, m_transform.angle);
	force += nc::Vector2{ 0,100 };

	m_velocity += (force * dt);
	m_velocity *= 0.99f;

	m_transform.position = m_transform.position + (m_velocity * dt);


	//rotate
	if (Core::Input::IsPressed('A')) { m_transform.angle -= (nc::math::DegreesToRadians(m_rotationRate) * dt); }
	if (Core::Input::IsPressed('D')) { m_transform.angle += (nc::math::DegreesToRadians(m_rotationRate) * dt); }

	m_transform.position = nc::math::Clamp(m_transform.position, {0,0}, {800,600});

	m_transform.Update();

}

void Player::Draw(Core::Graphics& graphics)
{
	m_shape.Draw(graphics, m_transform);
}
