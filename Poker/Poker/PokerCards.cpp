#include "pch.h"
#include "PokerCards.h"
#include"DoubleLinkList.h"
#include <cstdlib>
#include <ctime>

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
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			cards[i][j].isKept = false;
		}
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


 


