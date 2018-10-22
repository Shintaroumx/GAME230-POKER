#pragma once
#include "PokerCards.h"

struct Node
{
	Cards data;
	Node* prev;
	Node* next;
};

class DoubleLinkList
{
public:
	DoubleLinkList();
	~DoubleLinkList();
	
	DoubleLinkList* CreateLinkList();
	void AddFirst(DoubleLinkList* list, Cards data);
	void AddLast(DoubleLinkList* list, Cards data);
	void PrintList(DoubleLinkList* list);
	void ShowHand(DoubleLinkList * list);
	int GetCardValue(DoubleLinkList* list, int index);
	char GetCardSuit(DoubleLinkList* list, int index);
	void DrawFromList(DoubleLinkList* list1, DoubleLinkList* list2);
	void CopyList(DoubleLinkList * list1, DoubleLinkList * list2);
	void DiscardFromList(DoubleLinkList* list, int index);
	void SortList(DoubleLinkList* list);
	int GetLength(DoubleLinkList * list);

	/*bool isEmpty();
	int Getlength();
	void TraverseLinkList();
	void TraverseBackLinkList();
	void InsertNodeAfter(int position,Cards card);
	void InsertNodeBefore(int position);
	void DeleteNode(int position);
	void DeleteLinkList();*/

private:
	Node* head;
	//Node* tail;
};







