#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

typedef struct ListItem ListItem;
typedef struct DoubleLinkedList DoubleLinkedList;
struct ListItem{
  ListItem *next;
  ListItem *prev;
  int data;
};

struct DoubleLinkedList{
  ListItem *head;
  ListItem *tail;
  int count;
};

int doubleLinkedListAddItemToHead(DoubleLinkedList *list, ListItem *item);
int doubleLinkedListAddItemToTail(DoubleLinkedList *list, ListItem *item);
ListItem* doubleLinkedListRemoveItemFromHead(DoubleLinkedList *ListPtr);
ListItem* doubleLinkedListRemoveItemFromTail(DoubleLinkedList *ListPtr);

#endif // DOUBLELINKEDLIST_H
