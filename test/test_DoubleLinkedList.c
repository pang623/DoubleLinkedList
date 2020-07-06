#include "unity.h"

#include "DoubleLinkedList.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_doubleLinkedListAddItemToHead_given_item2_expect_head_points_item2_and_tail_points_item1_and_both_item1next_and_item2prev_points_to_null() {
	//initialise items and list
	ListItem item1 = {NULL, NULL, 10};
	ListItem item2 = {NULL, NULL, 20};
	DoubleLinkedList list = {&item1, &item1, 1};		//item1 had been added to linked list, this way of adding item can only be done when the list does not has any item
	//add item 2 to head
	int c = doubleLinkedListAddItemToHead(&list, &item2);
	//test the linked list
	TEST_ASSERT_EQUAL_PTR(&item2, list.head);
	TEST_ASSERT_EQUAL_PTR(&item1, list.tail);
	TEST_ASSERT_EQUAL_PTR(&item1, item2.next);
	TEST_ASSERT_EQUAL_PTR(&item2, item1.prev);
	TEST_ASSERT_EQUAL_PTR(NULL, item2.prev);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.next);
	TEST_ASSERT_EQUAL(2, c);							//check that the count has incremented by one after adding 1 item
	TEST_ASSERT_EQUAL(10, item1.data);
	TEST_ASSERT_EQUAL(20, item2.data);
}

void test_doubleLinkedListAddItemToTail_given_item2_expect_tail_points_item2_and_head_points_item1_and_both_item2next_and_item1prev_points_to_null() {
	//initialise items and list
	ListItem item1 = {NULL, NULL, 10};
	ListItem item2 = {NULL, NULL, 20};
	DoubleLinkedList list = {&item1, &item1, 1};		//item1 had been added to linked list
	//add item 2 to tail
	int c = doubleLinkedListAddItemToTail(&list, &item2);
	//test the linked list
	TEST_ASSERT_EQUAL_PTR(&item1, list.head);
	TEST_ASSERT_EQUAL_PTR(&item2, list.tail);
	TEST_ASSERT_EQUAL_PTR(&item2, item1.next);
	TEST_ASSERT_EQUAL_PTR(&item1, item2.prev);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.prev);
	TEST_ASSERT_EQUAL_PTR(NULL, item2.next);
	TEST_ASSERT_EQUAL(2, c);							//check that the count has incremented by one after adding 1 item
	TEST_ASSERT_EQUAL(10, item1.data);
	TEST_ASSERT_EQUAL(20, item2.data);
}

void test_doubleLinkedListRemoveItemFromHead_given_list_expect_lastItem_to_be_removed_from_head_of_linked_list_every_time_the_function_is_executed_item_removed_in_order_of_321() {
	//initialise items and list
	ListItem* itemRemoved;								//itemRemoved is a pointer to struct ListItem, it contains the address of the item removed
	ListItem item1 = {NULL, NULL, 10};
	ListItem item2 = {NULL, NULL, 20};
	ListItem item3 = {NULL, NULL, 30};
	DoubleLinkedList list = {&item1, &item1, 1};		//item1 had been added to linked list
	//add item2 to head of linked list
	doubleLinkedListAddItemToHead(&list, &item2);		//count = 2;
	//add item3 to head of linked list
	doubleLinkedListAddItemToHead(&list, &item3);		//count = 3;
	/*
	*at this point the head is pointing to item3, tail to item1
	*/
	//remove item3 from head of linked list
	itemRemoved = doubleLinkedListRemoveItemFromHead(&list);
	//start testing
	TEST_ASSERT_EQUAL_PTR(&item3, itemRemoved);			//check that the item removed is item 3
	TEST_ASSERT_EQUAL_PTR(&item2, list.head);
	TEST_ASSERT_EQUAL_PTR(NULL, item2.prev);
	TEST_ASSERT_EQUAL(2, list.count);				//check that the count is reduced by 1 after removing 1 item
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);		//check that the item3.next and item3.prev points to null
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->prev);
	TEST_ASSERT_EQUAL(30, itemRemoved->data);
	//remove item2 from head of linked list
	itemRemoved = doubleLinkedListRemoveItemFromHead(&list);
	TEST_ASSERT_EQUAL_PTR(&item2, itemRemoved);			//check that the item removed is item 2
	TEST_ASSERT_EQUAL_PTR(&item1, list.head);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.prev);
	TEST_ASSERT_EQUAL(1, list.count);				//check that the count is reduced by 1 after removing 1 item
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);		//check that the item2.next and item2.prev points to null
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->prev);
	TEST_ASSERT_EQUAL(20, itemRemoved->data);
	//remove item1 from head of linked list
	itemRemoved = doubleLinkedListRemoveItemFromHead(&list);
	TEST_ASSERT_EQUAL_PTR(&item1, itemRemoved);			//check that the item removed is item 1
	TEST_ASSERT_EQUAL_PTR(NULL, list.head);
	TEST_ASSERT_EQUAL_PTR(NULL, list.tail);
	TEST_ASSERT_EQUAL(0, list.count);				//check that the count is reduced by 1 after removing 1 item
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);		//check that the item1.next and item1.prev points to null
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->prev);
	TEST_ASSERT_EQUAL(10, itemRemoved->data);
	/*
	at this point the linked list has no item
	*/
	/*
	if the remove item function is executed when there are no more items in the list, no item will be removed,
	the function returns the itemRemoved as NULL, and both head and tail of the list points to null, count remains 0
	*/
	itemRemoved = doubleLinkedListRemoveItemFromHead(&list);	//keep on removing item although no item left in list
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved);						//check that there is no item removed
	TEST_ASSERT_EQUAL_PTR(NULL, list.head);							//check that head and tail do not point to any item
	TEST_ASSERT_EQUAL_PTR(NULL, list.tail);
	TEST_ASSERT_EQUAL(0, list.count);							//check that the count remain zero
}

void test_doubleLinkedListRemoveItemFromHead_given_list_expect_lastItem_to_be_removed_from_head_of_linked_list_every_time_the_function_is_executed_item_removed_in_order_of_123() {
	//initialise items and list
	ListItem* itemRemoved;
	ListItem item1 = {NULL, NULL, 10};
	ListItem item2 = {NULL, NULL, 20};
	ListItem item3 = {NULL, NULL, 30};
	DoubleLinkedList list = {&item1, &item1, 1};		//item1 had been added to linked list
	//add item2 to tail of linked list
	doubleLinkedListAddItemToTail(&list, &item2);		//count = 2;
	//add item3 to tail of linked list
	doubleLinkedListAddItemToTail(&list, &item3);		//count = 3;
	/*
	*at this point the head is pointing to item1, tail to item3
	*/
	//remove item1 from head of linked list
	itemRemoved = doubleLinkedListRemoveItemFromHead(&list);
	//start testing
	TEST_ASSERT_EQUAL_PTR(&item1, itemRemoved);			//check that the item removed is item 1
	TEST_ASSERT_EQUAL_PTR(&item2, list.head);
	TEST_ASSERT_EQUAL_PTR(NULL, item2.prev);
	TEST_ASSERT_EQUAL(2, list.count);				//check that the count is reduced by 1 after removing 1 item
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);		//check that the item1.next and item1.prev points to null
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->prev);
	TEST_ASSERT_EQUAL(10, itemRemoved->data);
	//remove item2 from head of linked list
	itemRemoved = doubleLinkedListRemoveItemFromHead(&list);
	TEST_ASSERT_EQUAL_PTR(&item2, itemRemoved);			//check that the item removed is item 2
	TEST_ASSERT_EQUAL_PTR(&item3, list.head);
	TEST_ASSERT_EQUAL_PTR(NULL, item3.prev);
	TEST_ASSERT_EQUAL(1, list.count);				//check that the count is reduced by 1 after removing 1 item
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);		//check that the item2.next and item2.prev points to null
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->prev);
	TEST_ASSERT_EQUAL(20, itemRemoved->data);
	//remove item1 from head of linked list
	itemRemoved = doubleLinkedListRemoveItemFromHead(&list);
	TEST_ASSERT_EQUAL_PTR(&item3, itemRemoved);			//check that the item removed is item 3
	TEST_ASSERT_EQUAL_PTR(NULL, list.head);
	TEST_ASSERT_EQUAL_PTR(NULL, list.tail);
	TEST_ASSERT_EQUAL(0, list.count);				//check that the count is reduced by 1 after removing 1 item
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);		//check that the item3.next and item3.prev points to null
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->prev);
	TEST_ASSERT_EQUAL(30, itemRemoved->data);
	/*
	at this point the linked list has no item
	*/
	/*
	if the remove item function is executed when there are no more items in the list, no item will be removed,
	the function returns the itemRemoved as NULL, and both head and tail of the list points to null, count remains 0
	*/
	itemRemoved = doubleLinkedListRemoveItemFromHead(&list);	//keep on removing item although no item left in list
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved);						//check that there is no item removed
	TEST_ASSERT_EQUAL_PTR(NULL, list.head);							//check that head and tail do not point to any item
	TEST_ASSERT_EQUAL_PTR(NULL, list.tail);
	TEST_ASSERT_EQUAL(0, list.count);
}

void test_doubleLinkedListRemoveItemFromTail_given_list_expect_lastItem_to_be_removed_from_tail_of_linked_list_every_time_the_function_is_executed_item_removed_in_order_of_321() {
	//initialise items and list
	ListItem* itemRemoved;
	ListItem item1 = {NULL, NULL, 10};
	ListItem item2 = {NULL, NULL, 20};
	ListItem item3 = {NULL, NULL, 30};
	DoubleLinkedList list = {&item1, &item1, 1};		//item1 had been added to linked list
	//add item2 to tail of linked list
	doubleLinkedListAddItemToTail(&list, &item2);		//count = 2
	//add item3 to tail of linked list
	doubleLinkedListAddItemToTail(&list, &item3);		//count = 3
	/*
	*at this point the head is pointing to item1, tail to item3
	*/
	//remove item3 from tail of linked list
	itemRemoved = doubleLinkedListRemoveItemFromTail(&list);
	//start testing
	TEST_ASSERT_EQUAL_PTR(&item3, itemRemoved);			//check that the item removed is item 3
	TEST_ASSERT_EQUAL_PTR(&item2, list.tail);
	TEST_ASSERT_EQUAL_PTR(NULL, item2.next);
	TEST_ASSERT_EQUAL(2, list.count);				//check that the count is reduced by 1 after removing 1 item
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);		//check that the item3.next and item3.prev points to null
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->prev);
	TEST_ASSERT_EQUAL(30, itemRemoved->data);
	//remove item2 from tail of linked list
	itemRemoved = doubleLinkedListRemoveItemFromTail(&list);
	TEST_ASSERT_EQUAL_PTR(&item2, itemRemoved);			//check that the item removed is item 2
	TEST_ASSERT_EQUAL_PTR(&item1, list.tail);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.next);
	TEST_ASSERT_EQUAL(1, list.count);				//check that the count is reduced by 1 after removing 1 item
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);		//check that the item2.next and item2.prev points to null
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->prev);
	TEST_ASSERT_EQUAL(20, itemRemoved->data);
	//remove item1 from tail of linked list
	itemRemoved = doubleLinkedListRemoveItemFromTail(&list);
	TEST_ASSERT_EQUAL_PTR(&item1, itemRemoved);			//check that the item removed is item 1
	TEST_ASSERT_EQUAL_PTR(NULL, list.head);
	TEST_ASSERT_EQUAL_PTR(NULL, list.tail);
	TEST_ASSERT_EQUAL(0, list.count);				//check that the count is reduced by 1 after removing 1 item
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);		//check that the item1.next and item1.prev points to null
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->prev);
	TEST_ASSERT_EQUAL(10, itemRemoved->data);
	/*
	at this point the linked list has no item
	*/
	/*
	if the remove item function is executed when there are no more items in the list, no item will be removed,
	the function returns the itemRemoved as NULL, and both head and tail of the list points to null, count remains 0
	*/
	itemRemoved = doubleLinkedListRemoveItemFromTail(&list);	//keep on removing item although no item left in list
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved);						//check that there is no item removed
	TEST_ASSERT_EQUAL_PTR(NULL, list.head);							//check that head and tail do not point to any item
	TEST_ASSERT_EQUAL_PTR(NULL, list.tail);
	TEST_ASSERT_EQUAL(0, list.count);
}



void test_doubleLinkedListRemoveItemFromTail_given_list_expect_lastItem_to_be_removed_from_tail_of_linked_list_every_time_the_function_is_executed_item_removed_in_order_of_123() {
	//initialise items and list
	ListItem* itemRemoved;
	ListItem item1 = {NULL, NULL, 10};
	ListItem item2 = {NULL, NULL, 20};
	ListItem item3 = {NULL, NULL, 30};
	DoubleLinkedList list = {&item1, &item1, 1};		//item1 had been added to linked list
	//add item2 to head of linked list
	doubleLinkedListAddItemToHead(&list, &item2);		//count = 2
	//add item3 to head of linked list
	doubleLinkedListAddItemToHead(&list, &item3);		//count = 3
	/*
	*at this point the head is pointing to item3, tail to item1
	*/
	//remove item1 from tail of linked list
	itemRemoved = doubleLinkedListRemoveItemFromTail(&list);
	//start testing
	TEST_ASSERT_EQUAL_PTR(&item1, itemRemoved);			//check that the item removed is item 1
	TEST_ASSERT_EQUAL_PTR(&item2, list.tail);
	TEST_ASSERT_EQUAL_PTR(NULL, item2.next);
	TEST_ASSERT_EQUAL(2, list.count);				//check that the count is reduced by 1 after removing 1 item
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);		//check that the item3.next and item3.prev points to null
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->prev);
	TEST_ASSERT_EQUAL(10, itemRemoved->data);
	//remove item2 from tail of linked list
	itemRemoved = doubleLinkedListRemoveItemFromTail(&list);
	TEST_ASSERT_EQUAL_PTR(&item2, itemRemoved);			//check that the item removed is item 2
	TEST_ASSERT_EQUAL_PTR(&item3, list.tail);
	TEST_ASSERT_EQUAL_PTR(NULL, item3.next);
	TEST_ASSERT_EQUAL(1, list.count);				//check that the count is reduced by 1 after removing 1 item
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);		//check that the item2.next and item2.prev points to null
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->prev);
	TEST_ASSERT_EQUAL(20, itemRemoved->data);
	//remove item3 from tail of linked list
	itemRemoved = doubleLinkedListRemoveItemFromTail(&list);
	TEST_ASSERT_EQUAL_PTR(&item3, itemRemoved);			//check that the item removed is item 3
	TEST_ASSERT_EQUAL_PTR(NULL, list.head);
	TEST_ASSERT_EQUAL_PTR(NULL, list.tail);
	TEST_ASSERT_EQUAL(0, list.count);				//check that the count is reduced by 1 after removing 1 item
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);		//check that the item1.next and item1.prev points to null
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->prev);
	TEST_ASSERT_EQUAL(30, itemRemoved->data);
	/*
	at this point the linked list has no item
	*/
	/*
	if the remove item function is executed when there are no more items in the list, no item will be removed,
	the function returns the itemRemoved as NULL, and both head and tail of the list points to null, count remains 0
	*/
	itemRemoved = doubleLinkedListRemoveItemFromTail(&list);	//keep on removing item although no item left in list
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved);						//check that there is no item removed
	TEST_ASSERT_EQUAL_PTR(NULL, list.head);							//check that head and tail do not point to any item
	TEST_ASSERT_EQUAL_PTR(NULL, list.tail);
	TEST_ASSERT_EQUAL(0, list.count);
}






