#ifndef INTEGERLISTITEM_H
#define INTEGERLISTITEM_H

typedef struct IntegerListItem IntegerListItem;
struct IntegerListItem{
  ListItem *next;
  ListItem *prev;
  int data;
};

#endif // INTEGERLISTITEM_H
