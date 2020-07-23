#include "core.h"
#include "Game.h"

Game game;



bool Update(float dt) //delta time (60 fps) (1 / 60 = 0.016) (60 * 0.01667 = 1.0)
{
		return game.Update(dt);
}

void Draw(Core::Graphics& graphics)
{
	game.Draw(graphics);
}

int main()
{	
	game.Startup();

	char name[] = "CSC196";
	Core::Init(name, 800, 600,90);
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);

	Core::GameLoop();
	Core::Shutdown();	

	game.Shutdown();
}



