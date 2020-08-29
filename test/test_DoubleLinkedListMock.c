#include "unity.h"
#include "DoubleLinkedList.h"
#include "MyData.h"
#include "mock_MemAlloc.h"
#include "mock_DummyFree.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_doubleLinkedListCreateListItem_given_data_expect_list_item_created() {
  ListItem *itemPtr;
  ListItem item1 = {NULL, NULL, (char *)"SITI"};
  ListItem item2 = {NULL, NULL, (char *)"ABU ALI"};
  item1.next = &item2;
  item2.prev = &item1;
  
  memAlloc_ExpectAndReturn(sizeof(ListItem), &item1);
  itemPtr = doubleLinkedListCreateListItem((char *)"ABU ALI");
  TEST_ASSERT_EQUAL_PTR(&item1, itemPtr);
  TEST_ASSERT_EQUAL_PTR(NULL, itemPtr->next);
  TEST_ASSERT_EQUAL_PTR(NULL, itemPtr->prev);
  TEST_ASSERT_EQUAL_STRING("ABU ALI", itemPtr->data);
  
  memFree_Expect(itemPtr);
  doubleLinkedListFreeListItem(itemPtr);
}

void test_doubleLinkedListCreateListItem_given_data_structure_expect_list_item_created() {
  ListItem *itemPtr;
  MyData *dataPtr;
  MyData data1 = {"SKIP", 8, 7.3436};
  MyData data2 = {"HERE", 908, 1.2345};
  ListItem item1 = {NULL, NULL, &data2};
  ListItem item2 = {NULL, NULL, &data1};
  item2.next = &item1;
  item1.prev = &item2;
  
  memAlloc_ExpectAndReturn(sizeof(ListItem), &item1);
  itemPtr = doubleLinkedListCreateListItem(&data1);
  TEST_ASSERT_EQUAL_PTR(&item1, itemPtr);
  TEST_ASSERT_EQUAL_PTR(NULL, itemPtr->next);
  TEST_ASSERT_EQUAL_PTR(NULL, itemPtr->prev);
  TEST_ASSERT_EQUAL_PTR(&data1, itemPtr->data);
  
  dataPtr = (MyData *)itemPtr->data;
  TEST_ASSERT_EQUAL_STRING("SKIP", dataPtr->string);
  TEST_ASSERT_EQUAL(8, dataPtr->val1);
  TEST_ASSERT_EQUAL_FLOAT(7.3436, dataPtr->val2);
  
  memFree_Expect(itemPtr);
  doubleLinkedListFreeListItem(itemPtr);
}

void test_doubleLinkedListFreeListItem() {
  ListItem item1 = {NULL, NULL, (char *)"Hi"};
  ListItem *itemPtr = &item1;
  memFree_Expect(itemPtr);
  doubleLinkedListFreeListItem(itemPtr);
}

void test_doubleLinkedListFreeListItem_given_data_struct() {
  MyData data1 = {"HALT", 345, 1.23456};
  ListItem item1 = {NULL, NULL, &data1};
  ListItem *itemPtr = &item1;
  memFree_Expect(itemPtr);
  doubleLinkedListFreeListItem(itemPtr);
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
  MyData dataStruct = {"SKIP", 8, 7.3436};
  ListItem item = {NULL, NULL, (void *)36874};
  ListItem item1 = {NULL, NULL, (char *)"bamboo"};
  ListItem item2 = {NULL, NULL, &dataStruct};
  DoubleLinkedList list = {&item, &item2, 3};
  DoubleLinkedList *listPtr = &list;
  
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
  memFree_Expect(listPtr);
  doubleLinkedListFreeList(listPtr, dummyFree);
}