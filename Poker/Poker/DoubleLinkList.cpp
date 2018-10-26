#include "pch.h"
#include "DoubleLinkList.h"
#include "PokerCards.h"
#include<iostream>
#include<stdio.h>
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


using namespace std;
//struct DoubleLinkList { Node* head; };


DoubleLinkList::DoubleLinkList() {
	//head = new Node;
	//head=NULL ;
}
DoubleLinkList::~DoubleLinkList() {
	//delete  head;
}


DoubleLinkList* DoubleLinkList::CreateLinkList(){
	DoubleLinkList* list = new DoubleLinkList;
	list->head = NULL;
	//list->tail = NULL;
	return list;
}


void DoubleLinkList::AddFirst(DoubleLinkList * list, Cards data) {
	Node* n = new Node;
	n->data = data;
	if (list->head == NULL) {
		n->next = list->head;
		list->head = n;
	}
	else {
		n->next = list->head;
		list->head = n;
		n->next->prev = n;
		n->prev = NULL;
	}
}


void DoubleLinkList::PrintList(DoubleLinkList* list){
	Node* n = list->head;
	int count = 1;

	cout << endl;
	while (n != NULL)
	{
		if (n->data.suit == 'C') {
			if (n->data.value == 10) {
				cout <<"["<< count<<"] "<<"10 of " << "Clubs  ";
			}
			else
				cout << "[" << count << "] " << n->data.showValue << " of " << "Clubs  ";
		}

		if (n->data.suit == 'D') {
			if (n->data.value == 10) {
				cout << "[" << count << "] " << "10 of " << "Diamonds  ";
			}
			else
			    cout << "[" << count <<"] " << n->data.showValue << " of " << "Diamonds  ";
		}

		if (n->data.suit == 'H') {
			if (n->data.value == 10) {
				cout << "[" << count << "] " << "10 of " << "Hearts  ";
			}
			else
			    cout << "[" << count << "] " << n->data.showValue << " of " << "Hearts  ";
		}

		if (n->data.suit == 'S') {
			if (n->data.value == 10) {
				cout << "[" << count <<"] " << "10 of " << "Spades  ";
			}
			else
			    cout << "[" << count << "] " << n->data.showValue << " of " << "Spades  ";
		}
		n = n->next;
		count++;
	}
	cout << endl;
}


string isKept(Node* n) {
	if (n->data.isKept)
		return " (Kept)";
	else
		return"";
}


void DoubleLinkList::ShowHand(DoubleLinkList* list) {
	SortList(list);
	Node* n = list->head;
	int count = 1;
	cout << endl;
	cout << "Your hand contains:" << endl;
	while (n != NULL)
	{
		if (count == 1) cout << "A: ";
		if (count == 2) cout << "B: ";
		if (count == 3) cout << "C: ";
		if (count == 4) cout << "D: ";
		if (count == 5) cout << "E: ";

		if (n->data.suit == 'C') {
			if (n->data.value == 10) {
				cout << "10 of " << "Clubs" << isKept(n) << endl;
			}
			else
				cout << n->data.showValue << " of " << "Clubs" << isKept (n)<<endl;
		}

		if (n->data.suit == 'D') {
			if (n->data.value == 10) {
				cout << "10 of " << "Diamonds" << isKept(n) << endl;
			}
			else
				cout << n->data.showValue << " of " << "Diamonds" << isKept(n) << endl;
		}

		if (n->data.suit == 'H') {
			if (n->data.value == 10) {
				cout << "10 of " << "Hearts" << isKept(n) << endl;
			}
			else
				cout << n->data.showValue << " of " << "Hearts" << isKept(n) << endl;
		}

		if (n->data.suit == 'S') {
			if (n->data.value == 10) {
				cout << "10 of " << "Spades" << isKept(n) << endl;
			}
			else
				cout << n->data.showValue << " of " << "Spades" << isKept(n) << endl;
		}
		n = n->next;
		count++;
	}
	cout << endl;
}


Cards DoubleLinkList::GetCard(DoubleLinkList* list, int index) {
	Node* n = list->head;
	while (index > 0)
	{
		n = n->next;
		--index;
	}
	return n->data;
}


int DoubleLinkList::GetNodeIndex(DoubleLinkList* list, Cards node) {
	int index = 0;
	if (list->head == NULL) {
		cout << "Error Code:GetNodeIndex" << endl;
		return 0;
	}
	Node* n = list->head;
	while (n ->next!= NULL) {
		if (n->data.value == node.value && n->data.suit == node.suit)return index;
		n = n->next;
		index++;
	}
}


void DoubleLinkList::ModifyNode(DoubleLinkList* list, int index,Cards node){
	Node* n = list->head;
	while (index > 0)
	{
		if (n->next != NULL) {
			n = n->next;
		}
		else {
			n->next = NULL;
		}
		--index;
	}
	n->data = node;
}


void DoubleLinkList::DrawFromList(DoubleLinkList* list1, DoubleLinkList* list2, int count) {
	if (list1->head == NULL) {
		cout << "Error! Code:DrawFromList" << endl;
		return;
	}
	while (count > 0&& list1->head != NULL) {
		Node* n = list1->head;
		if (n->next != NULL) {
			list1->head = n->next;
			n->next->prev = NULL;
		}
		else {
			list1->head = NULL;
		}
	AddFirst(list2, n->data);
	delete n;
	count--;

	}
}


void DoubleLinkList::CopyList(DoubleLinkList* list1, DoubleLinkList* list2) {
	if (list1->head == NULL) {
		cout << "Error! Code:CopyList" << endl;
		return;
	}

	Node* n = list1->head;
	if (list1->head != NULL) {
		while (n != NULL) {
			AddFirst(list2, n->data);
			n = n->next;
		}
	}
}


void DoubleLinkList::DeleteFromList(DoubleLinkList* list, DoubleLinkList* list2, int index)
{
	int count = index;
	if (index == 0)
	{
		cout << "Error! Code:DeleteFromList" << endl;
		return;
	}

	Node* p = list->head;
	while (count - 1 > 0)
	{
		if (p != NULL) {
			if (p->next != NULL) {
				p = p->next;
			}
			else {
				p->next = NULL;
			}
			--count;
		}
	}

	if (p != NULL) {
		if (p->prev == NULL && p->next != NULL) {
			list->head = p->next;
			p->next->prev = NULL;
			p->data.isKept = false;
			AddFirst(list2, p->data);
			delete p;
		}
		else if (p->prev == NULL && p->next == NULL) {
			list->head = NULL;
			p->data.isKept = false;
			AddFirst(list2, p->data);
			delete p;
		}
		else if (p->next != NULL) {
			p->prev->next = p->next;
			p->next->prev = p->prev;
			p->data.isKept = false;
			AddFirst(list2, p->data);
			delete p;
		}
		else if (p->next == NULL) {
			p->prev->next = NULL;
			AddFirst(list2, p->data);
			p->data.isKept = false;
			delete p;
		}
	}



	Node* n = list->head;
	if (list->head != NULL) {
		if (n->next == NULL)n->data.isKept = true;
		while (n->next != NULL) {
			n->data.isKept = true;
			n = n->next;
		}
	}
}


void DoubleLinkList::SortList(DoubleLinkList* list)
{
	Node* p = NULL;
	Node* q =NULL;
	if (list->head == NULL) {
		cout << "Error! Code:SortList" << endl;
		return;
	}
	else {
		for (p = list->head; p->next != NULL; p = p->next)
		{
			for (q = p->next; q != NULL; q = q->next)
			{
				if (q->data.value < p->data.value)
				{
					swap(q->data, p->data);
				}
				if (q->data.value == p->data.value) {
					if (q->data.suit < p->data.suit) {
						swap(q->data, p->data);
					}
				}
			}
		}
	}
}


void  DoubleLinkList::EmptyList(DoubleLinkList* list) {
	if (list->head == NULL) {
		cout << "Error! Code:EmptyList" << endl;
		return;
	}

	while (list->head!= NULL) {
		Node* n = list->head;
		if (n->next != NULL) {
			list->head = n->next;
			n->next->prev = NULL;
		}
		else {
			list->head = NULL;
		}
		delete n;
	}
}


int DoubleLinkList::GetLength(DoubleLinkList* list)
{
	int count = 0;
	Node* n = list->head;
	while (n != NULL)
	{
		++count;
		n = n->next;
	}
	return count;
}


int DoubleLinkList::JudgeCards(DoubleLinkList* hand) {
	int handCards[5];
	char cardsSuit[5];
	int a = 0;
	int countStraight = 0;
	bool inSwitch;

	inSwitch = true;

	for (int i = 0; i < 5; i++) {
		handCards[i] = GetCard(hand, i ).value;
		cardsSuit[i] = GetCard(hand, i ).suit;
	}

	if ((handCards[0] == handCards[1] && handCards[1] == handCards[2]&& handCards[2] == handCards[3]) || (handCards[1] == handCards[2] && handCards[2] == handCards[3] && handCards[3] == handCards[4])) {
		return 25;//Four of a kind
	}

	for (a = 0; a < 3; a++) {
		switch (a)
		{
		case 0:
			if (handCards[a] == handCards[a + 1] && handCards[a + 1] == handCards[a + 2]) {
			if (handCards[3] == handCards[4]) {
				return 9;//Fullhouse
				break;
			}
			else {
				return 3;//Three of a kind
				break;
			}
		}

		case 1:
			if (handCards[a] == handCards[a + 1] && handCards[a + 1] == handCards[a + 2]) {
				if (handCards[0] == handCards[4]) {
					return 9;//Fullhouse
					break;
				}
				else {
					return 3;//Three of a kind
					break;
				}
			}

		case 2:
			if (handCards[a] == handCards[a + 1] && handCards[a + 1] == handCards[a + 2]) {
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
	}


	
	if ((handCards[0] == handCards[1] && handCards[2] == handCards[3]) || (handCards[1] == handCards[2] && handCards[3] == handCards[4])|| (handCards[0] == handCards[1] && handCards[3] == handCards[4])) {
		return 2;//Two pair
	}

	else {
		for (int i = 0; i < 4; i++) {
			if (handCards[i] == handCards[i + 1] && handCards[i] > 10) {
				return 1;//One pair larger than J
			}
		}		
	}

	if (cardsSuit[0] == cardsSuit[1] &&cardsSuit[1]== cardsSuit[2]&&cardsSuit[2] == cardsSuit[3]&&cardsSuit[3] == cardsSuit[4]) {
		for (int i = 0; i < 4; i++) {
			if (handCards[i + 1] - handCards[i] == 1) {
				countStraight++;
			}
		}
		if (countStraight == 4) {
			if (handCards[0] == 10) {
				return 800;
			}//Royal flush
			else {
				return 50;
			}//Straight flush
		}

		else {
			return 6;
		}//Flush

	}
	return 0;
}


void DoubleLinkList::SwapBetweenLists(DoubleLinkList* list1, DoubleLinkList* list2, int index1,int index2) {
	if (list1->head == NULL||list2->head == NULL) {
		cout << "Error! Code:SwapBetweenLists" << endl;
		return;
	}
	Cards temp = GetCard(list1, index1-1);
	ModifyNode(list1, index1- 1, GetCard(list2,index2-1));
	ModifyNode(list2, index2 - 1, temp);
}



 
 


