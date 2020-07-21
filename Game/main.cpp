#include "core.h"
#include "Math/Math.h"
#include "Math/Random.h"
//#include "Math/Vector2.h"
#include "Math/Color.h"
#include "Math/Transform.h"
#include "Graphics/Shape.h"
#include "Actors/Player.h"
#include "Actors/Enemy.h"
#include <Object\Scene.h>
#include <iostream>
#include <string>
#include <list>
#include <vector>

nc::Scene scene;

float t{ 0 };
float frametime;
float spawntimer{ 0 };

bool Update(float dt) //delta time (60 fps) (1 / 60 = 0.016) (60 * 0.01667 = 1.0)
{
	frametime = dt;
	
	bool quit = Core::Input::IsPressed(Core::Input::KEY_ESCAPE);

	scene.Update(dt);
	
	spawntimer += dt;
	if (spawntimer >= 3.0f)
	{
		spawntimer = 0.0f;
		
		//add enemy to scene
		nc::Actor* actor = new Enemy;
		actor->Load("enemy.txt");
		dynamic_cast<Enemy*>(actor)->SetTarget(scene.GetActor<Player>());
		actor->GetTransform().position = nc::Vector2{ nc::random(0, 800), nc::random(0,600) };
		dynamic_cast<Enemy*>(actor)->setThrust(nc::random(50, 150));
		scene.AddActor(actor);
	}

	
	return quit;
}

void Draw(Core::Graphics& graphics)
{
	graphics.DrawString(10, 10, std::to_string(frametime).c_str());
	graphics.DrawString(10, 20, std::to_string(1.0f/frametime).c_str());
	
	scene.Draw(graphics);
}

int main()
{	
	nc::Actor* player = new Player;
	player->Load("player.txt");
	scene.AddActor(player);
	
	for (int i = 0; i < 10; i++)
	{
		nc::Actor* enemy = new Enemy;
		enemy->Load("enemy.txt");
		dynamic_cast<Enemy*>(enemy)->SetTarget(player);
		enemy->GetTransform().position = nc::Vector2{ nc::random(0, 800), nc::random(0,600) };
		dynamic_cast<Enemy*>(enemy)->setThrust(nc::random(50, 150));
		scene.AddActor(enemy);
	}

	char name[] = "CSC196";
	Core::Init(name, 800, 600,90);
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);

	Core::GameLoop();
	Core::Shutdown();
}



