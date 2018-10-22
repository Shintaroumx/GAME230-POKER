#include "pch.h"
#include "DoubleLinkList.h"
#include "PokerCards.h"
#include<iostream>
#include<stdio.h>
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


void DoubleLinkList::AddLast(DoubleLinkList * list, Cards data){
	if (list->head == NULL){
	   AddFirst(list, data);
	   return;
	}

    Node* tail = list->head;
	Node* n = new Node;

	while (tail->next != NULL)
		tail = tail->next;

	if (tail->next != NULL) 
		tail->next->prev= n;
		 	 
	n->data = data;
	n->next = NULL;
	n->prev = tail;
	tail->next = n;
}


void DoubleLinkList::PrintList(DoubleLinkList* list){
	Node* n = list->head;
	while (n != NULL)
	{
		if (n->data.suit == 'C') {
			if (n->data.value == 10) {
				cout << "10 of " << "Clubs  ";
			}
			else
				cout << n->data.showValue << " of " << "Clubs  ";
		}

		if (n->data.suit == 'D') {
			if (n->data.value == 10) {
				cout << "10 of " << "Diamonds  ";
			}
			else
			    cout << n->data.showValue << " of " << "Diamonds  ";
		}

		if (n->data.suit == 'H') {
			if (n->data.value == 10) {
				cout << "10 of " << "Hearts  ";
			}
			else
			    cout << n->data.showValue << " of " << "Hearts  ";
		}

		if (n->data.suit == 'S') {
			if (n->data.value == 10) {
				cout << "10 of " << "Spades  ";
			}
			else
			    cout << n->data.showValue << " of " << "Spades  ";
		}
		n = n->next;
	}
	cout << endl;
}


void DoubleLinkList::ShowHand(DoubleLinkList* list) {
	Node* n = list->head;
	while (n != NULL)
	{
		if (n->data.suit == 'C') {
			if (n->data.value == 10) {
				cout << "10 of " << "Clubs" << endl;
			}
			else
				cout << n->data.showValue << " of " << "Clubs" << endl;
		}

		if (n->data.suit == 'D') {
			if (n->data.value == 10) {
				cout << "10 of " << "Diamonds" << endl;
			}
			else
				cout << n->data.showValue << " of " << "Diamonds" << endl;
		}

		if (n->data.suit == 'H') {
			if (n->data.value == 10) {
				cout << "10 of " << "Hearts" << endl;
			}
			else
				cout << n->data.showValue << " of " << "Hearts" << endl;
		}

		if (n->data.suit == 'S') {
			if (n->data.value == 10) {
				cout << "10 of " << "Spades" << endl;
			}
			else
				cout << n->data.showValue << " of " << "Spades" << endl;
		}
		n = n->next;
	}
	cout << endl;
}



int DoubleLinkList::GetCardValue(DoubleLinkList* list, int index){
	Node* n = list->head;
	while (index > 0)
	{
		n = n->next;
		--index;
	}
	return n->data.value;
}


char DoubleLinkList::GetCardSuit(DoubleLinkList * list, int index){
	Node* n = list->head;
	while (index > 0)
	{
		n = n->next;
		--index;
	}
	return n->data.suit;
}


void DoubleLinkList::DrawFromList(DoubleLinkList* list1, DoubleLinkList* list2){
	if (list1->head == NULL){
		cout << "Error!" << endl;
		return;
	}

	Node* n = list1->head;
	list1->head = n->next;
	n->next->prev = NULL;
	AddFirst(list2, n->data);
	delete n;
}


void DoubleLinkList::CopyList(DoubleLinkList* list1, DoubleLinkList* list2) {
	if (list1->head == NULL) {
		cout << "Error!" << endl;
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



void DoubleLinkList::DiscardFromList(DoubleLinkList* list, int index)
{
	if (index == 0)
	{
		cout << "Error!" << endl;
		return;
	}

	Node* p = list->head;
	while (index - 1 > 0)
	{
		p = p->next;
		--index;
	}

	Node* n = p->next;
	p->next = n->next;
	n->next->prev = p;
	delete n;
}


void DoubleLinkList::SortList(DoubleLinkList* list)   //Ã°ÅÝÅÅÐò
{
	Node* p = new Node;
	Node* q = new Node;
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


 //bool DoubleLinkList::isEmpty()
 //{
	// if (head->next = NULL) {
	//	 return true;
	// }
	// else {
	//	 return false;
	// }
 //}


 //int DoubleLinkList::Getlength(){
	// int n = 0;
	// Node* ptemp = head->next;
	// while (ptemp != NULL) {
	//	 n++;
	//	 ptemp = ptemp->next;
	// }
	// return n;
 //}


 //
 //void DoubleLinkList::InsertNodeAfter(int position,Cards card){
	// if (position<0||position>Getlength()+1) {
	//	 cout << "Invalid position!" << endl;
	//	 exit(EXIT_FAILURE);
	// }
	// else {
	//	 Node*pnew;
	//	 Node* ptemp;
	//	 pnew = new Node;
	//	pnew->data = card;
	//	 ptemp = head;

	//	 while (position-- > 1) {
	//		 ptemp = ptemp->next;
	//	 }

	//	 if (ptemp->next != NULL) {
	//		 ptemp->next->prev= pnew;
	//	 }
	//	 pnew->next = ptemp->next;
	//	 pnew->prev = ptemp;
	//	 ptemp->next = pnew;
	// }
 //}


 //void DoubleLinkList::InsertNodeBefore(int position){
	// if (position<0 || position>Getlength() + 1) {
	//	 cout << "Invalid position!" << endl;
	//	 exit(EXIT_FAILURE);
	// }
	// else {
	//	 Node*pnew;
	//	 Node* ptemp;
	//	 pnew = new Node;
	//	 //pnew->data = d;
	//	 ptemp = head;

	//	 while (position-- > 1) {
	//		 ptemp = ptemp->next;
	//	 }

	//	 ptemp->prev->next = pnew;
	//	 pnew->prev= ptemp->prev;
	//	 pnew->next = ptemp;
	//	 ptemp->prev = pnew;
	// }
 //}


 //void DoubleLinkList::DeleteNode(int position) {
	// if (position<0 || position>Getlength()) {
	//	 cout << "Invalid position!" << endl;
	//	 exit(EXIT_FAILURE);
	// }
	// else {
	//	 Node* pdelete;
	//	 Node* ptemp;
	//	 ptemp = head;

	//	 while (position-- > 1) {
	//		 ptemp = ptemp->next;
	//	 }
	//	 pdelete = ptemp->next;
	//	 if (pdelete->next != NULL) {
	//		 pdelete->next->prev = ptemp;
	//	 }
	//	 ptemp->next = pdelete->next;
	//	 delete pdelete;
	//	 pdelete = NULL;
	// }
 //
 //}


 //void DoubleLinkList::DeleteLinkList(){
	// Node* pdelete;
	// Node* ptemp;
	// pdelete = head->next;
	// while (pdelete!=NULL) {
	//	 ptemp = pdelete->next;
	//	 head->next = ptemp;
	//	 if (ptemp!=NULL) {
	//		 ptemp->prev = head;
	//	 }
	//	 delete pdelete;
	//	 pdelete = ptemp;
	// }
 //}

 
 


