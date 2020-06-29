#include <iostream>
#include "helper.h"
#include"mathlib.h"
#include "core.h"
#include "painter.h"
#include <vector>

Painter painter;


int function1()
{
    int i = 5;

    for (int j = 0; j < 5; j++)
    {
        i++;
    }

    return i;
}

int function2() 
{
    int j = 3;
    j = j + function1();

    return j;
}

bool update(float dt)
{
    bool quit = false;
    quit = Core::Input::IsPressed(Core::Input::KEY_ESCAPE);

    painter.Update(dt);
    
    return quit;
}

void Draw(Core::Graphics& graphics)
{
    graphics.SetColor(RGB(rand() % 255, rand() % 255, rand() % 255));
    /*graphics.DrawLine(static_cast<float>(rand() % 800), static_cast<float>(rand() % 600), static_cast<float>(rand() % 
        800), static_cast<float>(rand() % 600));*/
    /*graphics.SetBackgroundColor(RGB(rand() % 255, rand() % 255, rand() % 255));*/

    painter.Draw(graphics);
    
   /* int x, y;
    Core::Input::GetMousePos(x, y);
    nc::vector2 point{ x,y };
    graphics.DrawLine(0, 0, point.x, point.y);*/
  
}

int main()
{
    painter.Load("paint.txt");
    char name[] = "Hoffman";
    Core::Init(name, 640, 480);
    Core::RegisterUpdateFn(update);
    Core::RegisterDrawFn(Draw);
    Core::GameLoop();
    Core::Shutdown();

    painter.Save("paint.txt");

}

