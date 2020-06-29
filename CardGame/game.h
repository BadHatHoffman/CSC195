#pragma once
#include "deck.h"
#include "player.h"
#include <vector>

class Game
{
public:
	enum ePlayer
	{
		Player1,	// 0
		Player2		// 1
	};

public:
	Game() {}

	void StartGame();
	void StartRound();

	bool IsGameOver() { return m_gameOver; }
	void AddPlayer(const Player& player) { m_players.push_back(player); }

	const Player& GetWinner() const
	{
		return winner;
	}

	const void SetWinner(Player& player);

private:
	bool m_gameOver{ false };

	Deck m_deck;
	std::vector<Player> m_players;

	Player winner;
};

