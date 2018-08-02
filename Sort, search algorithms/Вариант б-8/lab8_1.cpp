#include <iostream>
#include <ctime>
#include <cstdlib>

enum CardRank { Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };
enum CardSuit { Spades, Clubs, Diamonds, Hearts }; // пики, трефы, бубны, червы

struct Card
{
	CardRank m_rank;
	CardSuit m_suit;
};

void printCards(Card * _cards, int _N)
{
	int card = 0;

	for (int i = 0; i < _N; i++)
	{
		switch (_cards[i].m_rank)
		{
		case Seven: std::cout << "7"; break;
		case Eight: std::cout << "8"; break;
		case Nine: std::cout << "9"; break;
		case Ten: std::cout << "10"; break;
		case Jack: std::cout << "Jack"; break;
		case Queen: std::cout << "Queen"; break;
		case King: std::cout << "King"; break;
		case Ace: std::cout << "Ace"; break;
		}

		switch (_cards[i].m_suit)
		{
		case Spades: card = 0; std::cout << "-S" << std::ends; break;
		case Clubs: card = 1; std::cout << "-C" << std::ends; break;
		case Diamonds: card = 2; std::cout << "-D" << std::ends; break;
		case Hearts: card = 3; std::cout << "-H" << std::ends; break;
		}
		if (i < _N && card < _cards[i + 1].m_suit)
			std::cout << "\t";
	}
	std::cout << std::endl;
}

void selectionSort(Card  * _cards, int _N)
{
	for (int i = 0; i < _N - 1; i++)
	{
		int lowIndex = i;
		for (int j = i + 1; j < _N; j++)
			if (_cards[j].m_suit < _cards[lowIndex].m_suit ||
				(_cards[j].m_suit == _cards[lowIndex].m_suit &&
					_cards[j].m_rank > _cards[lowIndex].m_rank))
				lowIndex = j;

		std::swap(_cards[lowIndex], _cards[i]);
	}
}

int main()
{
	srand((unsigned)time(nullptr));

	Card cards[33], pl1[10], pl2[10], pl3[10], rest[2];

	//инициализируем
	int counter = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++)
		{
			cards[counter].m_suit = (CardSuit)i;
			cards[counter++].m_rank = (CardRank)j;
		}
	
	//перемешиваем
	for (int i = 0; i < 17; i++) std::swap(cards[i], cards[rand() % 31]);

	//распределяем карты 
	for (int i = 0 , j = 0; i < 10; i++) pl1[j++] = cards[i];

	for (int i = 10 , j = 0; i < 20; i++) pl2[j++] = cards[i];

	for (int i = 20 , j = 0; i < 30; i++) pl3[j++] = cards[i];

	for (int i = 30 , j = 0; i < 32; i++) rest[j++] = cards[i];

	//сортируем наши колоды
	selectionSort(pl1, 10);
	selectionSort(pl2, 10);
	selectionSort(pl3, 10);
	selectionSort(rest, 2);

	//выводим все колоды
	printCards(pl1, 10);
	printCards(pl2, 10);
	printCards(pl3, 10);
	printCards(rest, 2);

	return 0;
}
