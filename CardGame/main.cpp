// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "card.h"
#include "deck.h"
#include "game.h"
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    // random seed
    srand(static_cast<unsigned int>(time(NULL)));

    // create game
    Game game;

    // add players
#ifdef NDEBUG
    string name;

    cout << "enter name: ";
    getline(cin, name);
    game.AddPlayer(Player{ name });

    cout << "enter name: ";
    getline(cin, name);
    game.AddPlayer(Player{ name });
#else
    game.AddPlayer(Player{ "Player1" });
    game.AddPlayer(Player{ "Player2" });
#endif // NDEBUG

    // play game
    game.StartGame();

    while (!game.IsGameOver())
    {
        game.StartRound();
    }
}
