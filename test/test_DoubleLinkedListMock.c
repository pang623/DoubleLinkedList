#include "unity.h"
#include "DoubleLinkedList.h"
#include "IntegerListItem.h"
#include "mock_MemAlloc.h"
#include "mock_DummyFree.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_doubleLinkedListCreateListItem() {
  char *name = "ABU ALI";
  char *name1 = "SITI";
  ListItem *itemPtr;
  ListItem item1 = {NULL, NULL, name1};
  ListItem item2 = {NULL, NULL, name};
  item1.next = &item2;
  item2.prev = &item1;
  
  memAlloc_ExpectAndReturn(sizeof(ListItem), &item1);
  itemPtr = doubleLinkedListCreateListItem(name);
  TEST_ASSERT_EQUAL_PTR(&item1, itemPtr);
  TEST_ASSERT_EQUAL_PTR(NULL, itemPtr->next);
  TEST_ASSERT_EQUAL_PTR(NULL, itemPtr->prev);
  TEST_ASSERT_EQUAL_STRING("ABU ALI", itemPtr->data);
  
  memFree_Expect(itemPtr);
  doubleLinkedListFreeListItem(itemPtr);
}

void test_doubleLinkedListCreateListItem_given_data_structure_expect_list_item_created() {
  ListItem *itemPtr;
  Data *dataPtr;
  Data data1 = {"SKIP", 8, 7.3436};
  ListItem item1 = {NULL, NULL, (char *)"haha"};
  
  memAlloc_ExpectAndReturn(sizeof(ListItem), &item1);
  itemPtr = doubleLinkedListCreateListItem(&data1);
  TEST_ASSERT_EQUAL_PTR(&item1, itemPtr);
  TEST_ASSERT_EQUAL_PTR(NULL, itemPtr->next);
  TEST_ASSERT_EQUAL_PTR(NULL, itemPtr->prev);
  TEST_ASSERT_EQUAL_PTR(&data1, itemPtr->data);
  
  dataPtr = (Data *)itemPtr->data;
  TEST_ASSERT_EQUAL_STRING("SKIP", dataPtr->string);
  TEST_ASSERT_EQUAL(8, dataPtr->val1);
  TEST_ASSERT_EQUAL_FLOAT(7.3436, dataPtr->val2);
  
  memFree_Expect(itemPtr);
  doubleLinkedListFreeListItem(itemPtr);
}

void test_doubleLinkedListFreeListItem() {
  ListItem item1 = {NULL, NULL, (char *)"Hi"};
  memFree_Expect(&item1);
  doubleLinkedListFreeListItem(&item1);
}

void test_doubleLinkedListFreeListItem_given_data_struct() {
  Data data1 = {"HALT", 345, 1.23456};
  ListItem item1 = {NULL, NULL, &data1};
  memFree_Expect(&item1);
  doubleLinkedListFreeListItem(&item1);
}

void test_doubleLinkedListCreateList() {
  DoubleLinkedList *listPtr;
  ListItem item1 = {NULL, NULL, (void *)30};
  DoubleLinkedList list1 = {&item1, &item1, 1};
  
  memAlloc_ExpectAndReturn(sizeof(DoubleLinkedList), &list1);
  listPtr = doubleLinkedListCreateList();
  TEST_ASSERT_EQUAL_PTR(&list1, listPtr);
  TEST_ASSERT_EQUAL_PTR(NULL, listPtr->head);
  TEST_ASSERT_EQUAL_PTR(NULL, listPtr->tail);
  TEST_ASSERT_EQUAL(0, listPtr->count);
  
  memFree_Expect(listPtr);
  doubleLinkedListFreeList(listPtr, dummyFree);
}

void test_doubleLinkedListFreeList_given_data() {
  Data dataStruct = {"SKIP", 8, 7.3436};
  ListItem item = {NULL, NULL, (void *)36874};
  ListItem item1 = {NULL, NULL, (char *)"bamboo"};
  ListItem item2 = {NULL, NULL, &dataStruct};
  DoubleLinkedList list = {&item, &item2, 3};
  
  item.next = &item1;
  item1.next = &item2;
  item1.prev = &item;
  item2.prev = &item1;
  
  dummyFree_Expect(item.data);
  memFree_Expect(&item);
  dummyFree_Expect(item1.data);
  memFree_Expect(&item1);
  dummyFree_Expect(item2.data);
  memFree_Expect(&item2);
  memFree_Expect(&list);
  doubleLinkedListFreeList(&list, dummyFree);
}