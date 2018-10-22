#include "pch.h"
#include"DoubleLinkList.h"
#include "PokerCards.h"
#include <iostream>
#include<string>

#define _CRTDBG_MAP_ALLOC
#define _CRTDBG_MAP_ALLOC_NEW
#include <cstdlib>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif


DoubleLinkList list;
PokerCards pokerCards;
Cards cards[52];
DoubleLinkList* deck = list.CreateLinkList();
DoubleLinkList* hand = list.CreateLinkList();
int balance=5;

void InitialDeck() {
	pokerCards.Initial(cards);
	pokerCards.Shuffle(cards,52);
	for (int i = 0; i < 52; i++) {
		list.AddLast(deck, cards[i]);
	}
}


void FirstHand() {
	list.DrawFromList(deck, hand);
	list.DrawFromList(deck, hand);
	list.DrawFromList(deck, hand);
	list.DrawFromList(deck, hand);
	list.DrawFromList(deck, hand);
	//list.PrintList(hand);
}


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF |
		_CRTDBG_LEAK_CHECK_DF);

	std::string showDeck;
	bool printOver = false;
	bool GameOver = false;

	InitialDeck();
	FirstHand();

	while (!GameOver) {
		while (!printOver) {
			std::cin >> showDeck;
			if (showDeck == "deck") {
				DoubleLinkList* showDeckList = list.CreateLinkList();
				list.CopyList(deck, showDeckList);
				list.SortList(showDeckList);
				list.PrintList(showDeckList);
				printOver = true;
			}
		}
		printOver = false;

	}


	getchar();
}

