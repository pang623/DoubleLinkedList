#ifndef INTEGERLISTITEM_H
#define INTEGERLISTITEM_H

typedef struct IntegerListItem IntegerListItem;
struct IntegerListItem{
  ListItem *next;
  ListItem *prev;
  int data;
};

typedef struct Data Data;
struct Data{
  char *string;
  int val1;
  float val2;
};

#endif // INTEGERLISTITEM_H
