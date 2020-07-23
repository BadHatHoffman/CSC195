#include "Game.h"
#include "Math/Math.h"
#include "Math/Random.h"
//#include "Math/Vector2.h"
#include "Math/Color.h"
#include "Math/Transform.h"
#include "Graphics/Shape.h"
#include "Actors/Player.h"
#include "Actors/Enemy.h"
#include <Object\Scene.h>
#include "Graphics/ParticleSystem.h"
#include <iostream>
#include <string>
#include <list>
#include <vector>

const int Game::WIDTH = 800;
const int Game::HEIGHT = 800;


void Game::Startup()
{
	g_particleSystem.Startup();
	m_scene.Startup();
	m_scene.SetGame(this);
	
}

void Game::Shutdown()
{
	g_particleSystem.Shutdown();
	m_scene.Shutdown();
}

bool Game::Update(float dt)
{
	m_frametime = dt;
	bool quit = Core::Input::IsPressed(Core::Input::KEY_ESCAPE);

	switch (m_state)
	{
	case Game::eState::INIT:
		break;
	case Game::eState::TITLE:
		if (Core::Input::IsPressed(VK_SPACE))
		{
			m_state = eState::START_GAME;
		}
		break;
	case Game::eState::START_GAME:
	{
		Player* player = new Player;
		player->Load("player.txt");
		m_scene.AddActor(player);

		for (int i = 0; i < 10; i++)
		{
			Enemy* enemy = new Enemy;
			enemy->Load("enemy.txt");
			dynamic_cast<Enemy*>(enemy)->SetTarget(player);
			enemy->GetTransform().position = nc::Vector2{ nc::random(0, 800), nc::random(0,600) };
			dynamic_cast<Enemy*>(enemy)->setThrust(nc::random(50, 150));
			m_scene.AddActor(enemy);
		}

		m_state = eState::GAME;
	}
		break;
	case Game::eState::GAME:
		m_spawntimer += dt;
		if (m_spawntimer >= 3.0f)
		{
			m_spawntimer = 0.0f;

			//add enemy to scene
			nc::Actor* actor = new Enemy;
			actor->Load("enemy.txt");
			dynamic_cast<Enemy*>(actor)->SetTarget(m_scene.GetActor<Player>());
			actor->GetTransform().position = nc::Vector2{ nc::random(0, 800), nc::random(0,600) };
			dynamic_cast<Enemy*>(actor)->setThrust(nc::random(50, 150));
			m_scene.AddActor(actor);
		}

		m_scene.Update(dt);
		break;
	case Game::eState::GAME_OVER:
		break;
	default:
		break;
	}

	

	

	Player* player = m_scene.GetActor<Player>();


	if (Core::Input::IsPressed(Core::Input::BUTTON_LEFT))
	{
		int x, y;
		Core::Input::GetMousePos(x, y);

		nc::Color colors[] = { nc::Color::white, nc::Color::blue, nc::Color::yellow };
		nc::Color color = colors[rand() % 3];

		g_particleSystem.Create({ x,y }, 0, 180, 30, color, 1, 100, 200);
	}
	g_particleSystem.Update(dt);
	
	return quit;
}

void Game::Draw(Core::Graphics& graphics)
{
	graphics.SetColor(nc::Color{ 1,1,1 });
	graphics.DrawString(10, 10, std::to_string(m_frametime).c_str());
	graphics.DrawString(10, 20, std::to_string(1.0f / m_frametime).c_str());

	g_particleSystem.Draw(graphics);
	

	switch (m_state)
	{
	case Game::eState::INIT:
		break;
	case Game::eState::TITLE:
		graphics.SetColor(nc::Color::green);
		graphics.DrawString(400, 300, "VECTOROIDS");
		break;
	case Game::eState::START_GAME:
		break;
	case Game::eState::GAME:
		graphics.SetColor(nc::Color::white);
		graphics.DrawString(700, 10, std::to_string(m_score).c_str());
		m_scene.Draw(graphics);
		break;
	case Game::eState::GAME_OVER:
		graphics.SetColor(nc::Color::red);
		graphics.DrawString(400, 300, "GAME OVER");
		break;
	default:
		break;
	}
}
