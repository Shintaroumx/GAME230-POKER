#include "pch.h"
#include"DoubleLinkList.h"
#include "PokerCards.h"
#include <iostream>
#include<string>
using namespace std;


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
DoubleLinkList* drop = list.CreateLinkList();
DoubleLinkList* showDeckList = list.CreateLinkList();
int balance=5;
bool bChooseOver = false;



void InitialDeck() {
	pokerCards.Initial(cards);
	pokerCards.Shuffle(cards,52);
	for (int i = 0; i < 52; i++) {
		list.AddFirst(deck, cards[i]);
	}
}


void ReInitialDeck() {
	list.DrawFromList(deck, hand, list.GetLength(deck));
	int dropPile =list.GetLength(drop);
	for (int i = 0; i < dropPile; i++) {
		cards[i] = list.GetCard(drop, i);
	}
	list.EmptyList(drop);
	pokerCards.Shuffle(cards, dropPile);
	for (int i = 0; i < dropPile; i++) {
		list.AddFirst(deck, cards[i]);
	}
	/*for (int i = 1; i <= left; i++) {
		list.DeleteFromList(deck, list.GetNodeIndex(deck, list.GetCard(hand, i-1))+1);
	}*/
}


void NewHand() {
	balance--;
	cout << "You pay a $1 ante and now have $" << balance  << endl;
	list.DrawFromList(deck, hand,5);
	//list.PrintList(hand);
}


int DiscardCards(string input) {
	int count = 0;
	if (input.find('A') > 1000 && input.find('a') > 1000) {
		list.DeleteFromList(hand,drop, 1);
		count++;
	}
	if (input.find('B') > 1000 && input.find('b') > 1000) {
		if (count == 1) {
			list.DeleteFromList(hand, drop, 1);
		}
		else
			list.DeleteFromList(hand, drop, 2 - count);
		count++;
	}
	if (input.find('C') > 1000 && input.find('c') > 1000) {
		if (count == 2) {
			list.DeleteFromList(hand, drop, 1);
		}
		else
			list.DeleteFromList(hand, drop, 3 - count);
		count++;
	}
	if (input.find('D') > 1000 && input.find('d') > 1000) {
		if (count == 3) {
			list.DeleteFromList(hand, drop, 1);
		}
		else
			list.DeleteFromList(hand, drop, 4 - count);
		count++;
	}
	if (input.find('E') > 1000 && input.find('e') > 1000) {
		if (count == 4) {
			list.DeleteFromList(hand, drop, 1);
		}
		else
			list.DeleteFromList(hand, drop, 5 - count);
		count++;
	}
	bChooseOver = true;
	return count;
}


void DiscardAll() {
	list.DeleteFromList(hand, drop, 1);
	list.DeleteFromList(hand, drop, 1);
	list.DeleteFromList(hand, drop, 1);
	list.DeleteFromList(hand, drop, 1);
	list.DeleteFromList(hand, drop, 1);
}


void ShowIfAwarded() {
	if (list.JudgeCards(hand)!=0) {
		cout << "Congratulations! You got ";
		switch (list.JudgeCards(hand)) {
		case 1:
			cout << "One Pair ";
			break;
		case 2:
			cout << "Two Pair ";
			break;
		case 3:
			cout << "Three of a Kind ";
			break;
		case 6:
			cout << "Flush ";
			break;
		case 25:
			cout << "Four of a Kind ";
			break;
		case 9:
			cout << "Full House ";
			break;
		case 50:
			cout << "Straight Flush ";
			break;
		case 800:
			cout << "Royal Flush ";
			break;
		}
		balance += list.JudgeCards(hand);
		cout << "and earned $" << list.JudgeCards(hand) << "!" << endl<<"Now you have $"<<balance<<endl;
	}
	else cout << "No poker hand scored :(" << endl;
}


void ShowOptions() {
	cout << "OPTIONS..." << endl;
	cout << "  - Type the letters for the cards you wish to keep. (i.e., 'acd')" << endl << "  - Type 'deck' to view the cards remaining in the deck." << endl << "  - Type 'none' to discard all cards in your hand." << endl;
	cout << "  - Type 'all' to keep all cards in your hand." << endl << "  - Type 'exit' to exit the game." << endl << "  - Type 'swap' to CHEAT and swap a card in your hand with one in the deck. " << endl;
	cout << "  YOUR CHOICE: ";
}


void ShowDeckList() {
	list.CopyList(deck, showDeckList);
	list.SortList(showDeckList);
}


void SwapToCheat(string input) {
	bool bChooseHand=false;
	bool bChooseDeck=false;
	bool bFirstTime = true;
	int x, y;

	while (!bChooseHand) {
		cout << "Please choose the card in your hand you want to swap" << endl;
		cin >> input;
		if (input == "A" || input == "a")x = 1;
		if (input == "B" || input == "b")x = 2;
		if (input == "C" || input == "c")x = 3;
		if (input == "D" || input == "d")x = 4;
		if (input == "E" || input == "e")x = 5;

		if (input != "A"&&input != "a"&&input != "B"&&input != "b"&&input != "C"&&input != "c"&&input != "D"&&input != "d"&&input != "E"&&input != "e") {
			cout << "Invalid input!" << endl;
			bChooseHand = false;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else {
			bChooseHand = true;
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}

	while (bChooseHand && !bChooseDeck) {
		if (bFirstTime) {
			ShowDeckList();
			bFirstTime = false;
		}
		if (!bFirstTime) {
			cout << "Please choose the card in the deck you want to swap" << endl;
			list.PrintList(showDeckList);
			cout<<endl;
			int input2;
			cin >> input2;
			y = input2;
			if (y > list.GetLength(deck)||y<=0) {
				cout << "Invalid input!" << endl;
				bChooseDeck = false;
				cin.clear();
				cin.ignore(10000,'\n');
			}
			else bChooseDeck = true;
		}
	}

	if (bChooseDeck) {
		list.SwapBetweenLists(hand, showDeckList, x, y);
		list.ModifyNode(deck, list.GetNodeIndex(deck, list.GetCard(hand, x - 1)), list.GetCard(showDeckList, y - 1));
		list.EmptyList(showDeckList);
	}
	bFirstTime = true;
}


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF |
		_CRTDBG_LEAK_CHECK_DF);

	std::string showDeck;
	bool printOver = false;
	bool GameOver = false;
	bool bNewRound = false;
	string input;

	cout << "Welcome to Command Line Poker!" << endl;
	InitialDeck();
	cout << "You have started with $" << balance << endl;
	NewHand();
	cout << endl;
	list.ShowHand(hand);
	cout << "The deck contains 47 cards" << endl << endl;
	ShowOptions();

	while (!GameOver) {
		if (!bChooseOver&&!bNewRound) {
			cin >> input;
			cout << endl;
			if (input == "deck"||input == "DECK") {
				ShowDeckList();
				list.PrintList(showDeckList);
				list.EmptyList(showDeckList);
				cout << endl;
			}
			else if (input == "none"||input=="NONE") {
				DiscardAll();
				if (list.GetLength(deck) <= 5) {
					int a = list.GetLength(deck);
					ReInitialDeck();
					cout << "You kept 0 and drew 5 cards!" << endl;
					list.DrawFromList(deck, hand, 5 - a);
				}
				else {
					cout << "You kept 0 and drew 5 cards!" << endl;
					list.DrawFromList(deck, hand, 5);
				}
				bChooseOver = true;
			}
			else if (input == "all" || input == "ALL") {
				cout << "You kept 5 and drew 0 cards!" << endl ;
				bChooseOver = true;
			}
			else if (input == "exit" || input == "EXIT") {
				break;
			}
			else if (input == "swap" || input == "SWAP") {
				SwapToCheat(input);
				list.ShowHand(hand);
			}
			else {
				int temp = DiscardCards(input);
				if (list.GetLength(deck) <= temp) {
					int a = list.GetLength(deck);
					ReInitialDeck();
					cout <<"You kept "<<5-temp<<" and drew "<<temp<<" cards!"<<endl;
					list.DrawFromList(deck, hand, temp - a);
				}
				else {
					cout << "You kept " << 5 - temp << " and drew " << temp << " cards!" ;
					list.DrawFromList(deck, hand, temp);
				}
			}
			cin.clear();
			cin.ignore(10000, '\n');
		}
		if (bChooseOver) {
			bChooseOver = false;
			list.ShowHand(hand);
			//cout << endl;
			ShowIfAwarded();
			bNewRound = true;
			if (balance > 0) {
				cout << endl << "Please enter instrutions to play another round...";
				getchar();
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "--------------------------------------------------------------------------------------------" << endl << endl;
				balance--;
				cout << "You pay a $1 ante and now have $" << balance << endl;
				DiscardAll();
				if (list.GetLength(deck) <= 5) {
					int a = list.GetLength(deck);
					ReInitialDeck();
					cout << "You kept 0 and drew 5 cards!" << endl;
					list.DrawFromList(deck, hand, 5 - a);
				}
				else {
					cout << "You kept 0 and drew 5 cards!" << endl;
					list.DrawFromList(deck, hand, 5);
				}
				cout << endl ;
				list.ShowHand(hand);
				cout << "The deck contains " << list.GetLength(deck) << " cards" << endl << endl;
				ShowOptions();
				bNewRound = false;
			}
		}
		if (balance == 0) {
			GameOver = true;
			cout << "You have run out of your money and GAME OVER" << endl;
			getchar();
			break;
		}
	}
	list.EmptyList(deck);
	list.EmptyList(showDeckList);
	list.EmptyList(hand);
	list.EmptyList(drop);
	
	delete deck;
	delete showDeckList;
	delete hand;
	delete drop;

	return 0;
}

