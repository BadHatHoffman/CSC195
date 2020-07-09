#include "core.h"
#include "Math/Math.h"
#include "Math/Random.h"
//#include "Math/Vector2.h"
#include "Math/Color.h"
#include "Math/Transform.h"
#include "Graphics/Shape.h"
#include <iostream>
#include <string>

const size_t NUM_POINTS = 40;
float speed = 300.0f;

std::vector<nc::Vector2> points = { { 0, -3 }, { 3, 3 }, { 0, 1 }, { -3, 3 }, { 0, -3 } };
nc::Color color{ 1,1,0 };
nc::Shape ship;
//nc::Shape box = { {points}, {color} };

nc::Transform transform{ {400,300}, 4,0 };
float t{ 0 };

float frametime;
float roundTime{ 0 };
bool gameOver{ false };

DWORD prevTime;
DWORD deltaTime;

bool Update(float dt) //delta time (60 fps) (1 / 60 = 0.016) (60 * 0.01667 = 1.0)
{
	//dt = current frame time - previous frame time
	DWORD time = GetTickCount(); //2452323
	deltaTime = time - prevTime;
	prevTime = time;
	
	t += dt *5.0f;


	frametime = dt;
	roundTime += dt;
	if (roundTime >= 5.0f) gameOver = true;

	dt *= 2.0f;
	if (gameOver) dt *= 0.5f;

	bool quit = Core::Input::IsPressed(Core::Input::KEY_ESCAPE);

	int x;
	int y;
	Core::Input::GetMousePos(x, y);

	//nc::Vector2 target = nc::Vector2{ x,y };
	//nc::Vector2 direction = target - position; // (head <- tail)
	//direction.Normalize();

	nc::Vector2 force{ 0,0 };
	if (Core::Input::IsPressed('W')) { force = nc::Vector2::forward * speed * dt; }
	nc::Vector2 direction = force;
	direction = nc::Vector2::Rotate(direction, transform.angle);
	transform.position = transform.position + direction;

	//rotate
	if (Core::Input::IsPressed('A')) { transform.angle -= (nc::math::DegreesToRadians(360.0f) * dt); }
	if (Core::Input::IsPressed('D')) { transform.angle += (nc::math::DegreesToRadians(360.0f) * dt); }

	transform.position = nc::math::Clamp(transform.position, { 0,0 }, { 800,600 });

	transform.position.x = nc::math::Clamp(transform.position.x, 0.0f, 800.0f);
	transform.position.y = nc::math::Clamp(transform.position.y, 0.0f, 600.0f);

	//translate
	//if (Core::Input::IsPressed(Core::Input::KEY_LEFT)) position += nc::Vector2{ -1.0f, 0.0f } * speed;
	//if (Core::Input::IsPressed(Core::Input::KEY_RIGHT)) position += nc::Vector2{ 1.0f, 0.0f } * speed;

	/*if (Core::Input::IsPressed('A')) { position += nc::Vector2::left *speed * dt; }
	if (Core::Input::IsPressed('D')) { position += nc::Vector2::right *speed * dt; }
	if (Core::Input::IsPressed('W')) { position += nc::Vector2::up *speed * dt; }
	if (Core::Input::IsPressed('S')) { position += nc::Vector2::down *speed * dt; }*/



	return quit;

}

void Draw(Core::Graphics& graphics)
{
	graphics.DrawString(10, 10, std::to_string(frametime).c_str());
	graphics.DrawString(10, 20, std::to_string(1.0f/frametime).c_str());
	graphics.DrawString(10, 30, std::to_string(deltaTime / 1000.0f).c_str());

	float v = (std::sin(t) + 1.0f);

	nc::Color c = nc::math::Lerp(nc::Color{ 0,0,1 }, nc::Color{ 1,0,0 }, t);
	graphics.SetColor(c);

	nc::Vector2 p = nc::math::Lerp(nc::Vector2{ 400,300 }, nc::Vector2{ 400, 100 }, v);
	graphics.DrawString(p.x, p.y, "Last Starfighter");

	if (gameOver) graphics.DrawString(400, 300, "Game Over");

	//rgb (8bits/1byte, 8,8) (0-255,0-255,0-255)
	//rgb(float, float, float) (0-1.0f,0-1.0f,0-1.0f,)

	/*graphics.SetColor(color);*/
	//graphics.DrawLine(static_cast<float>(rand() % 800), static_cast<float>(rand() % 600), static_cast<float>(rand() % 800), static_cast<float>(rand() % 600));

	ship.Draw(graphics,transform);
}

int main()
{	
	DWORD ticks = GetTickCount(); //how many ticks in a second
	std::cout << ticks/1000/60/60 << std::endl;
	prevTime = GetTickCount();

	ship.Load("ship.txt");
	/*ship.SetColor(nc::Color{ 1,1,1 });*/
	/*nc::Vector2 point;
	point.x = 4;
	point.y = 6;
	float x = nc::math::PI * 4;*/

	char name[] = "CSC196";
	Core::Init(name, 800, 600,90);
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);

	Core::GameLoop();
	Core::Shutdown();
}



