#include "DoubleLinkedList.h"
#include <stdio.h>

//Add ListItem to the head of double linked list and return the new count of items in the list.
//@1stparam Pointer to double linked list
//@2ndparam Pointer to list item
//@retval Number of items in the list after the addition
int doubleLinkedListAddItemToHead(DoubleLinkedList *list, ListItem *item) {
	item->next = list->head;
	(list->head)->prev = item;
	list->head = item;
	item->prev = NULL;
	list->count += 1;

	return list->count;
}

//Add ListItem to the tail of double linked list and return the new count of items in the list.
//@1stparam Pointer to double linked list
//@2ndparam Pointer to list item
//@retval Number of items in the list after the addition
int doubleLinkedListAddItemToTail(DoubleLinkedList *listPtr, ListItem *itemPtr) {
	itemPtr->prev = listPtr->tail;
	(listPtr->tail)->next = itemPtr;
	listPtr->tail = itemPtr;
	itemPtr->next = NULL;
	listPtr->count += 1;

	return listPtr->count;
}

//Remove ListItem from the head of double linked list and return the item removed from the list.
//@1stparam Pointer to double linked list
//@retval Item that is removed from the head of the list
ListItem* doubleLinkedListRemoveItemFromHead(DoubleLinkedList *ListPtr) {
	ListItem* lastItem;

	if(ListPtr->head == NULL) {			//before removing item, check if there is even any item to be removed
		ListPtr->count = 0;
		return NULL;					//no item to be removed, so return lastItem as NULL
	}else {
		lastItem = ListPtr->head;			//lastItem points to the item that is to be removed
		ListPtr->head = lastItem->next;		//item removed from head after this line
		if(ListPtr->head == NULL)			//after removing the item, if no item left, tail points to NULL
			ListPtr->tail = NULL;
		else
			(ListPtr->head)->prev = NULL;
		lastItem->next = NULL;				//make sure the next and prev of the removed item points to NULL
		lastItem->prev = NULL;
		ListPtr->count -= 1;				//decrement count by 1 every time an item is removed
	 }
	return lastItem;					//lastItem which contains the item removed is returned
}

//Remove ListItem from the tail of double linked list and return the item removed from the list.
//@1stparam Pointer to double linked list
//@retval Item that is removed from the tail of the list
ListItem* doubleLinkedListRemoveItemFromTail(DoubleLinkedList *ListPtr) {
	ListItem* LastItem;

	if(ListPtr->tail == NULL) {			//before removing item, check if there is even any item to be removed
		ListPtr->count = 0;
		return NULL;					//no item to be removed, so return LastItem as NULL
	}else {
		LastItem = ListPtr->tail;			//LastItem points to the item that is to be removed
		ListPtr->tail = LastItem->prev;		//item removed from tail after this line
		if(ListPtr->tail == NULL)			//after removing the item, if no item left, head points to NULL
			ListPtr->head = NULL;
		else
			(ListPtr->tail)->next = NULL;
		LastItem->next = NULL;				//make sure the next and prev of the removed item points to NULL
		LastItem->prev = NULL;
		ListPtr->count -= 1;				//decrement count by 1 every time an item is removed
	 }
	return LastItem;					//LastItem which contains the item removed is returned
}













