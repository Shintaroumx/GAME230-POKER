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
	Cards GetCard(DoubleLinkList * list, int index);
	int GetNodeIndex(DoubleLinkList * list, Cards node);
	void ModifyNode(DoubleLinkList * list, int index,Cards node);
	void DrawFromList(DoubleLinkList* list1, DoubleLinkList* list2,int count);
	void CopyList(DoubleLinkList * list1, DoubleLinkList * list2);
	void DeleteFromList(DoubleLinkList* list, DoubleLinkList* list2, int index);
	void SortList(DoubleLinkList* list);
	void EmptyList(DoubleLinkList * list);
	int GetLength(DoubleLinkList * list);
	int JudgeCards(DoubleLinkList* hand);
	void SwapBetweenLists(DoubleLinkList * list1, DoubleLinkList * list2,int index1,int index2);

private:
	Node* head;

};









