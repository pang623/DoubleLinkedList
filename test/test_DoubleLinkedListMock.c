#include "unity.h"
#include "DoubleLinkedList.h"
#include "mock_MemAlloc.h"
#include "IntegerListItem.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_doubleLinkedListFreeListItem() {
  IntegerListItem item1 = {NULL, NULL, 30};
  memFree_Expect(&item1);
  doubleLinkedListFreeListItem((ListItem *)&item1);
}

void test_doubleLinkedListCreateListItem() {
  char *name = "ABU ALI";
  ListItem *itemPtr = malloc(sizeof(ListItem));
  memAlloc_ExpectAndReturn(sizeof(ListItem), itemPtr);
  itemPtr = doubleLinkedListCreateListItem(name);
  TEST_ASSERT_EQUAL_PTR(NULL, itemPtr->next);
  TEST_ASSERT_EQUAL_PTR(NULL, itemPtr->prev);
  TEST_ASSERT_EQUAL("ABU ALI", itemPtr->data);
  free(itemPtr);
}

void test_doubleLinkedListCreateListItem_given_data_structure_expect_list_item_created() {
  Data dataStruct = {"SKIP", 8, 7.3436};
  ListItem *itemPtr = malloc(sizeof(ListItem));
  Data *dataPtr;
  
  memAlloc_ExpectAndReturn(sizeof(ListItem), itemPtr);
  itemPtr = doubleLinkedListCreateListItem(&dataStruct);
  dataPtr = (Data *)itemPtr->data;
  TEST_ASSERT_EQUAL_PTR(NULL, itemPtr->next);
  TEST_ASSERT_EQUAL_PTR(NULL, itemPtr->prev);
  TEST_ASSERT_EQUAL_STRING("SKIP", dataPtr->string);
  TEST_ASSERT_EQUAL(8, dataPtr->val1);
  TEST_ASSERT_EQUAL_FLOAT(7.3436, dataPtr->val2);
  free(itemPtr);
}

void test_doubleLinkedListCreateList() {
  DoubleLinkedList *listPtr = malloc(sizeof(DoubleLinkedList));
  memAlloc_ExpectAndReturn(sizeof(DoubleLinkedList), listPtr);
  listPtr = doubleLinkedListCreateList();
  TEST_ASSERT_EQUAL_PTR(NULL, listPtr->head);
  TEST_ASSERT_EQUAL_PTR(NULL, listPtr->tail);
  TEST_ASSERT_EQUAL(0, listPtr->count);
  free(listPtr);
}

/*
void test_doubleLinkedListFreeList() {
  Data dataStruct = {"SKIP", 8, 7.3436};
  ListItem item1 = {NULL, NULL, &dataStruct};
  DoubleLinkedList list = {&item1, &item1, 1};
  
  dummyFree_Expect(item1.data);
  doubleLinkedListFreeListItem_Expect(&item1);
  memFree_Expect(&list);
  doubleLinkedListFreeList(&list, dummyFree);
}*/