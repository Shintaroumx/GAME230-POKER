#include "pch.h"
#include "PokerCards.h"
#include"DoubleLinkList.h"
#include <cstdlib>
#include <ctime>

Cards cards[4][13];


PokerCards::PokerCards()
{
}


PokerCards::~PokerCards()
{
}

void PokerCards::Initial(Cards array[]){
	for (int i = 0; i < 4;i++) {
		cards[i][0].value =2;
		cards[i][1].value =3;
		cards[i][2].value =4;
		cards[i][3].value =5;
		cards[i][4].value =6;
		cards[i][5].value =7;
		cards[i][6].value =8;
		cards[i][7].value =9;
		cards[i][8].value =10;
		cards[i][9].value =11;//J
		cards[i][10].value =12;//Q
		cards[i][11].value =13;//K
		cards[i][12].value =14;//A
	}
	for (int i = 0; i < 4; i++) {
		cards[i][0].showValue = '2';
		cards[i][1].showValue = '3';
		cards[i][2].showValue = '4';
		cards[i][3].showValue = '5';
		cards[i][4].showValue = '6';
		cards[i][5].showValue = '7';
		cards[i][6].showValue = '8';
		cards[i][7].showValue = '9';
		cards[i][8].showValue = '0';
		cards[i][9].showValue = 'J';
		cards[i][10].showValue = 'Q';
		cards[i][11].showValue = 'K';
		cards[i][12].showValue = 'A';
	}
	for (int j = 0; j < 13;j++) {
		cards[0][j].suit='D';//Diamonds
		cards[1][j].suit = 'C';//Clubs
		cards[2][j].suit = 'S';//Spades
		cards[3][j].suit = 'H';//Hearts
	}

	for (int j = 0; j < 13; j++) {
		array[j] = cards[0][j];
		array[j + 13] = cards[1][j];
		array[j + 26] = cards[2][j];
		array[j + 39] = cards[3][j];
	} 
	
}


void PokerCards::Shuffle(Cards array[], int length) {
	int index;
	int value;
	Cards median;

	if (NULL == array || 0 == length) {
		return;
	}
	srand((int)time(0));
	for (index= 0; index < length; index++) {
		value= index + rand() % (length - index);

		median= array[index];
		array[index] = array[value];
		array[value] = median;
	}
}


int JudgeCards(DoubleLinkList* hand) {
	DoubleLinkList list;
	int handCards[5];
	char cardsSuit[5];
	int a=0;
	int countStraight=0;

	for (int i = 0; i < 5; i++) {
		handCards[i] = list.GetCardValue(hand, i + 1);
		cardsSuit[i] = list.GetCardSuit(hand, i + 1);
	}

	if ((handCards[0] == handCards[1] == handCards[2] == handCards[3]) || (handCards[1] == handCards[2] == handCards[3] == handCards[4])) {
		return 25;//Four of a kind
	}

	if (handCards[a] == handCards[a + 1] == handCards[a + 2]) {
		switch (a)
		{
		case 0:
			if (handCards[3] == handCards[4]) {
				return 9;//Fullhouse
				break;
			}
			else {
				return 3;//Three of a kind
				break;
			}

		case 1:
			if (handCards[0] == handCards[4]) {
				return 9;//Fullhouse
				break;
			}
			else {
				return 3;//Three of a kind
				break;
			}

		case 2:
			if (handCards[0] == handCards[1]) {
				return 9;//Fullhouse
				break;
			}
			else {
				return 3;//Three of a kind
				break;
			}
		}
	}

	else if ((handCards[0] == handCards[1] && handCards[1] == handCards[2]) || (handCards[1] == handCards[2] && handCards[3] == handCards[4])) {
		return 2;//Two pair
	}

	else {
		for (int i = 0; i < 4; i++) {
			if (handCards[i] == handCards[i + 1] && handCards[i] > 10) {
				return 1;//One pair larger than J
			}
		}
	}

	if (cardsSuit[0]== cardsSuit[1]== cardsSuit[2]== cardsSuit[3]== cardsSuit[4]) {
		for (int i = 0; i < 4; i++) {
			if (handCards[i + 1] - handCards[i] == 1) {
				countStraight++;
			}
		}
		if (countStraight == 4) {
			if (handCards[0] == 10)
				return 800;//Royal flush
			else
				return 50;//Straight flush
		}
		else
			return 6;//Flush
	}

	return 0;
}


