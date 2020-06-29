#include "game.h"

using namespace std;

void Game::StartGame()
{
	m_deck.Shuffle();

	cards_t cards = m_deck.m_cards;
	size_t halfSize = cards.size() / 2;

	cards_t splitLo{ cards.begin(), cards.begin() + halfSize };
	cards_t splitHi{ cards.begin() + halfSize, cards.end() };

	m_players[Player1].SetDeck(Deck{ splitLo });
	m_players[Player2].SetDeck(Deck{ splitHi });
}

void Game::StartRound()
{
	system("cls");

	cards_t cards;


	int winner = -1;
	while (winner == -1)
	{
		cards.push_front(m_players[Player1].DealCard());
		cards.push_front(m_players[Player2].DealCard());

		// p1card, p2card
		cout << m_players[Player1].GetName() << " " << cards[Player1] << endl;
		cout << m_players[Player2].GetName() << " " << cards[Player2] << endl;

		if (cards[Player1] == cards[Player2])
		{
			winner = Player1;
			cout << "War!!!\n";

			cards.push_back(m_players[Player1].DealCard());
			cards.push_back(m_players[Player2].DealCard());
		}
		if (cards[Player1] > cards[Player2])
		{
			winner = Player1;
		}
		else if (cards[Player2] > cards[Player1])
		{
			winner = Player2;
		}
	}

	cout << m_players[winner].GetName() << " Won!!!\n";
	/*m_players[winner].AddCard(cards[Player1]);
	m_players[winner].AddCard(cards[Player2]);*/
	for (size_t i = 0; i < cards.size(); i++)
	{
		m_players[winner].AddCard(cards[i]);
	}

	cout << m_players[Player1].GetName() << " : " << m_players[Player1].GetScoreCount() << endl;
	cout << m_players[Player2].GetName() << " : " << m_players[Player2].GetScoreCount() << endl;

	cout << "press enter to continue...";
	cin.ignore();

	//m_gameOver = true;
	if (m_players[Player1].GetScoreCount() == 52 || m_players[Player2].GetScoreCount() == 52)
	{
		SetWinner(m_players[winner]);
		cout << GetWinner().GetName() << " Has Won!!" << endl;
		m_gameOver = true;
	}
}

const void Game::SetWinner(Player& player) 
{
	winner = player;
}
