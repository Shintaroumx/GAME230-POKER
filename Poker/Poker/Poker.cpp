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
DoubleLinkList* showDeckList = list.CreateLinkList();
int balance=5;
bool bChooseOver = false;

void InitialDeck() {
	pokerCards.Initial(cards);
	pokerCards.Shuffle(cards,52);
	for (int i = 0; i < 52; i++) {
		list.AddLast(deck, cards[i]);
	}
}


void ReInitialDeck() {
	list.DrawFromList(deck, hand, list.GetLength(deck));
	InitialDeck();
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
		list.DeleteFromList(hand, 1);
		count++;
	}
	if (input.find('B') > 1000 && input.find('b') > 1000) {
		if (count == 1) {
			list.DeleteFromList(hand, 1);
		}
		else
			list.DeleteFromList(hand, 2 - count);
		count++;
	}
	if (input.find('C') > 1000 && input.find('c') > 1000) {
		if (count == 2) {
			list.DeleteFromList(hand, 1);
		}
		else
			list.DeleteFromList(hand, 3 - count);
		count++;
	}
	if (input.find('D') > 1000 && input.find('d') > 1000) {
		if (count == 3) {
			list.DeleteFromList(hand, 1);
		}
		else
			list.DeleteFromList(hand, 4 - count);
		count++;
	}
	if (input.find('E') > 1000 && input.find('e') > 1000) {
		if (count == 4) {
			list.DeleteFromList(hand, 1);
		}
		else
			list.DeleteFromList(hand, 5 - count);
		count++;
	}
	bChooseOver = true;
	return count;
}


void DiscardAll() {
	list.DeleteFromList(hand, 1);
	list.DeleteFromList(hand, 1);
	list.DeleteFromList(hand, 1);
	list.DeleteFromList(hand, 1);
	list.DeleteFromList(hand, 1);
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
			cout << "Three of a kind ";
			break;
		case 6:
			cout << "Flush ";
			break;
		case 25:
			cout << "Four of a kind ";
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
		cout << "and earned $" << list.JudgeCards(hand) << "!" << endl;
		balance += list.JudgeCards(hand);
		DiscardAll();
		list.DrawFromList(deck, hand, 5);
		cout << "Now you have a new hand" << endl;
		list.ShowHand(hand);
	}
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
	list.PrintList(showDeckList);
	list.EmptyList(showDeckList);
}


void SwapToCheat(string input) {
	cout << "Please choose the card in your hand you want to swap" << endl;
	cin >> input;
	int x, y;
	if (input == "A" || input == "a")x = 1;
	if (input == "B" || input == "b")x = 2;
	if (input == "C" || input == "c")x = 3;
	if (input == "D" || input == "d")x = 4;
	if (input == "E" || input == "e")x = 5;
	cout << "Please choose the card in the deck you want to swap" << endl;
	list.PrintList(deck);
	cin >> input;
	y = stoi(input);
	list.SwapBetweenLists(hand, deck, x, y);
}


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF |
		_CRTDBG_LEAK_CHECK_DF);

	std::string showDeck;
	bool printOver = false;
	bool GameOver = false;
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
		if (!bChooseOver) {
			cin >> input;
			if (input == "deck"||input == "DECK") {
				ShowDeckList();
			}
			else if (input == "none"||input=="NONE") {
				DiscardAll();
				balance--;
				cout << "You pay a $1 ante and now have $" << balance << endl;
				list.DrawFromList(deck, hand, 5);
				bChooseOver = true;
			}
			else if (input == "all" || input == "ALL") {
				balance--;
				cout << "You pay a $1 ante and now have $" << balance << endl;
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
					balance--;
					cout << "You pay a $1 ante and now have $" << balance << endl;
					list.DrawFromList(deck, hand, temp - a);
				}
				else {
					balance--;
					cout << "You pay a $1 ante and now have $" << balance << endl;
					list.DrawFromList(deck, hand, temp);
				}
			}
			cin.clear();
			cin.ignore();
		}
		if (bChooseOver) {
			bChooseOver = false;
			list.ShowHand(hand);
			cout << endl;
			ShowIfAwarded();
		}
		if (balance == 0) {
			GameOver = true;
			cout << "You have run out of your money and GAME OVER" << endl;
			getchar();
			break;
		}
		
	}
	
	return 0;
}

