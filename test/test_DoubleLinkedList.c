#include "unity.h"
#include "DoubleLinkedList.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/*

  before (count = 0)

  list

  head --> NULL
  tail --> NULL


  after (count = 0)

  list

  head --> NULL
  tail --> NULL

*/

void test_doubleLinkedListAddItemToHead_given_NULL_item_and_empty_list_expect_list_is_still_empty_after_adding() {
	//initialise items and list
	DoubleLinkedList list = {NULL, NULL, 0};
	//add NULL item to list
	int count = doubleLinkedListAddItemToHead(&list, NULL);
	//test the linked list
	TEST_ASSERT_EQUAL_PTR(NULL, list.head);
	TEST_ASSERT_EQUAL_PTR(NULL, list.tail);
	TEST_ASSERT_EQUAL(0, count);
}

/*

  before (count = 0)

  list

  head --> NULL
  tail --> NULL


  after (count = 1)

  list  |----> item1
        |
  head -|      next --->NULL
  tail         prev --->NULL
    |          ^ 10
    |__________|

*/

void test_doubleLinkedListAddItemToHead_given_item1_and_empty_list_expect_item1_added_to_list() {
	//initialise items and list
  ListItem item1 = {NULL, NULL, 10};
	DoubleLinkedList list = {NULL, NULL, 0};
	//add item1 to list
	int count = doubleLinkedListAddItemToHead(&list, &item1);
	//test the linked list
	TEST_ASSERT_EQUAL_PTR(&item1, list.head);
	TEST_ASSERT_EQUAL_PTR(&item1, list.tail);
  TEST_ASSERT_EQUAL_PTR(NULL, item1.next);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.prev);
  TEST_ASSERT_EQUAL(10, item1.data);
	TEST_ASSERT_EQUAL(1, count);
}

/*

  before (count = 1)

  list  |----> item1
        |
  head -|      next --->NULL
  tail         prev --->NULL
    |          ^ 10
    |__________|


  after (count = 1)

  list  |----> item1
        |
  head -|      next --->NULL
  tail         prev --->NULL
    |          ^ 10
    |__________|

*/

void test_doubleLinkedListAddItemToHead_given_NULL_item_and_list_containing_an_item_expect_no_item_is_added_and_list_remains_the_same() {
	//initialise items and list
  ListItem item1 = {NULL, NULL, 10};
	DoubleLinkedList list = {&item1, &item1, 1};
	//add NULL item to list
	int count = doubleLinkedListAddItemToHead(&list, NULL);
	//test the linked list
	TEST_ASSERT_EQUAL_PTR(&item1, list.head);
	TEST_ASSERT_EQUAL_PTR(&item1, list.tail);
  TEST_ASSERT_EQUAL_PTR(NULL, item1.next);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.prev);
  TEST_ASSERT_EQUAL(10, item1.data);
	TEST_ASSERT_EQUAL(1, count);
}

/*
  before (count = 1)

  list  |----> item1
        |
  head -|      next --->NULL
  tail         prev --->NULL
    |          ^ 10
    |__________|

  after (count = 2)

  list  |------> item2   |-----> item1
        |                |
  head -|         next --|        next-->NULL
  tail     NULL<--prev  <-------- prev
    |              20               ^ 10
    |_______________________________|

    add item2 to head

*/

void test_doubleLinkedListAddItemToHead_given_item2_and_list_containing_item1_expect_item2_added_to_head_of_list() {
	//initialise items and list
	ListItem item1 = {NULL, NULL, 10};
	ListItem item2 = {NULL, NULL, 20};
	DoubleLinkedList list = {&item1, &item1, 1};
	//add item2 to head
	int count = doubleLinkedListAddItemToHead(&list, &item2);
	//test the linked list
	TEST_ASSERT_EQUAL_PTR(&item2, list.head);
	TEST_ASSERT_EQUAL_PTR(&item1, list.tail);
	TEST_ASSERT_EQUAL_PTR(&item1, item2.next);
	TEST_ASSERT_EQUAL_PTR(&item2, item1.prev);
	TEST_ASSERT_EQUAL_PTR(NULL, item2.prev);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.next);
	TEST_ASSERT_EQUAL(2, count);
	TEST_ASSERT_EQUAL(10, item1.data);
	TEST_ASSERT_EQUAL(20, item2.data);
}

/*
  before (count = 2)

  list  |------> item2   |-----> item1
        |                |
  head -|         next --|        next-->NULL
  tail     NULL<--prev  <-------- prev
    |              20               ^ 10
    |_______________________________|


  after (count = 3)

  list  |------> item3   |-----> item2   |-----> item1
        |                |               |
  head -|         next --|        next --|        next --> NULL
  tail     NULL<--prev  <-------- prev  <-------- prev
    |              30              20              ^ 10
    |______________________________________________|

*/

void test_doubleLinkedListAddItemToHead_given_item3_and_list_containing_item1_and_item2_expect_item3_added_to_head_of_list() {
	//initialise items and list
	ListItem item1 = {NULL, NULL, 10};
	ListItem item2 = {NULL, NULL, 20};
  ListItem item3 = {NULL, NULL, 30};
  item1.prev = &item2;
  item2.next = &item1;
	DoubleLinkedList list = {&item2, &item1, 2};
	//add item3 to head
	int count = doubleLinkedListAddItemToHead(&list, &item3);
	//test the linked list
	TEST_ASSERT_EQUAL_PTR(&item3, list.head);
	TEST_ASSERT_EQUAL_PTR(&item1, list.tail);
  TEST_ASSERT_EQUAL_PTR(&item2, item3.next);
  TEST_ASSERT_EQUAL_PTR(NULL, item3.prev);
	TEST_ASSERT_EQUAL_PTR(&item1, item2.next);
  TEST_ASSERT_EQUAL_PTR(&item3, item2.prev);
  TEST_ASSERT_EQUAL_PTR(NULL, item1.next);
	TEST_ASSERT_EQUAL_PTR(&item2, item1.prev);
	TEST_ASSERT_EQUAL(3, count);
	TEST_ASSERT_EQUAL(10, item1.data);
	TEST_ASSERT_EQUAL(20, item2.data);
  TEST_ASSERT_EQUAL(30, item3.data);
}

//---------tests for doubleLinkedListAddItemToTail---------

/*

  before (count = 0)

  list

  head --> NULL
  tail --> NULL


  after (count = 0)

  list

  head --> NULL
  tail --> NULL

*/

void test_doubleLinkedListAddItemToTail_given_NULL_item_and_empty_list_expect_list_is_still_empty_after_adding() {
	//initialise items and list
	DoubleLinkedList list = {NULL, NULL, 0};
	//add NULL item to list
	int count = doubleLinkedListAddItemToTail(&list, NULL);
	//test the linked list
	TEST_ASSERT_EQUAL_PTR(NULL, list.head);
	TEST_ASSERT_EQUAL_PTR(NULL, list.tail);
	TEST_ASSERT_EQUAL(0, count);
}

/*

  before (count = 0)

  list

  head --> NULL
  tail --> NULL


  after (count = 1)

  list  |----> item1
        |
  head -|      next --->NULL
  tail         prev --->NULL
    |          ^ 10
    |__________|

*/

void test_doubleLinkedListAddItemToTail_given_item1_and_empty_list_expect_item1_added_to_list() {
	//initialise items and list
  ListItem item1 = {NULL, NULL, 10};
	DoubleLinkedList list = {NULL, NULL, 0};
	//add item1 to list
	int count = doubleLinkedListAddItemToTail(&list, &item1);
	//test the linked list
	TEST_ASSERT_EQUAL_PTR(&item1, list.head);
	TEST_ASSERT_EQUAL_PTR(&item1, list.tail);
  TEST_ASSERT_EQUAL_PTR(NULL, item1.next);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.prev);
  TEST_ASSERT_EQUAL(10, item1.data);
	TEST_ASSERT_EQUAL(1, count);
}

/*

  before (count = 1)

  list  |----> item1
        |
  head -|      next --->NULL
  tail         prev --->NULL
    |          ^ 10
    |__________|


  after (count = 1)

  list  |----> item1
        |
  head -|      next --->NULL
  tail         prev --->NULL
    |          ^ 10
    |__________|

*/

void test_doubleLinkedListAddItemToTail_given_NULL_item_and_list_containing_an_item_expect_no_item_is_added_and_list_remains_the_same() {
	//initialise items and list
  ListItem item1 = {NULL, NULL, 10};
	DoubleLinkedList list = {&item1, &item1, 1};
	//add NULL item to list
	int count = doubleLinkedListAddItemToTail(&list, NULL);
	//test the linked list
	TEST_ASSERT_EQUAL_PTR(&item1, list.head);
	TEST_ASSERT_EQUAL_PTR(&item1, list.tail);
  TEST_ASSERT_EQUAL_PTR(NULL, item1.next);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.prev);
  TEST_ASSERT_EQUAL(10, item1.data);
	TEST_ASSERT_EQUAL(1, count);
}

/*
  before (count = 1)

  list  |----> item1
        |
  head -|      next --->NULL
  tail         prev --->NULL
    |          ^ 10
    |__________|

  after (count = 2)

  list    |---->  item1   |---->  item2
          |               |
  head ---|       next ---|       next-->NULL
  tail    NULL<---prev   <--------prev
    |              10              ^ 20
    |______________________________|

    add item2 to tail

*/

void test_doubleLinkedListAddItemToTail_given_item2_and_list_containing_item1_expect_item2_added_to_tail_of_list() {
	//initialise items and list
	ListItem item1 = {NULL, NULL, 10};
	ListItem item2 = {NULL, NULL, 20};
	DoubleLinkedList list = {&item1, &item1, 1};
	//add item2 to tail
	int count = doubleLinkedListAddItemToTail(&list, &item2);
	//test the linked list
	TEST_ASSERT_EQUAL_PTR(&item1, list.head);
	TEST_ASSERT_EQUAL_PTR(&item2, list.tail);
  TEST_ASSERT_EQUAL_PTR(NULL, item1.prev);
	TEST_ASSERT_EQUAL_PTR(&item2, item1.next);
  TEST_ASSERT_EQUAL_PTR(&item1, item2.prev);
  TEST_ASSERT_EQUAL_PTR(NULL, item2.next);
	TEST_ASSERT_EQUAL(2, count);
	TEST_ASSERT_EQUAL(10, item1.data);
	TEST_ASSERT_EQUAL(20, item2.data);
}

/*
  before (count = 2)

  list    |---->  item1   |---->  item2
          |               |
  head ---|       next ---|       next-->NULL
  tail    NULL<---prev   <--------prev
    |              10              ^ 20
    |______________________________|

  after (count = 3)

  list    |---->  item1   |---->  item2   |---->  item3
          |               |               |
  head ---|       next ---|       next ---|        next --> NULL
  tail    NULL<---prev   <--------prev   <-------  prev
    |              10              20               ^ 30
    |_______________________________________________|

*/

void test_doubleLinkedListAddItemToTail_given_item3_and_list_containing_item1_and_item2_expect_item3_added_to_tail_of_list() {
	//initialise items and list
	ListItem item1 = {NULL, NULL, 10};
	ListItem item2 = {NULL, NULL, 20};
  ListItem item3 = {NULL, NULL, 30};
  item1.next = &item2;
  item2.prev = &item1;
	DoubleLinkedList list = {&item1, &item2, 2};
	//add item3 to tail
	int count = doubleLinkedListAddItemToTail(&list, &item3);
	//test the linked list
	TEST_ASSERT_EQUAL_PTR(&item1, list.head);
	TEST_ASSERT_EQUAL_PTR(&item3, list.tail);
  TEST_ASSERT_EQUAL_PTR(NULL, item3.next);
  TEST_ASSERT_EQUAL_PTR(&item2, item3.prev);
	TEST_ASSERT_EQUAL_PTR(&item3, item2.next);
  TEST_ASSERT_EQUAL_PTR(&item1, item2.prev);
  TEST_ASSERT_EQUAL_PTR(&item2, item1.next);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.prev);
	TEST_ASSERT_EQUAL(3, count);
	TEST_ASSERT_EQUAL(10, item1.data);
	TEST_ASSERT_EQUAL(20, item2.data);
  TEST_ASSERT_EQUAL(30, item3.data);
}

//--------tests for doubleLinkedListRemoveItemFromHead----------------//

/*
  before (count = 0)

  list

  head --> NULL
  tail --> NULL

  after (count = 0)

  list

  head --> NULL
  tail --> NULL

  no changes as no item is removed
  the function return item removed as NULL

*/

//list has no item, after execute remove function, nothing is removed, list remains the same
void test_doubleLinkedListRemoveItemFromHead_given_empty_list_expect_function_return_item_removed_as_NULL() {
  ListItem* itemRemoved;
  DoubleLinkedList list = {NULL, NULL, 0};                        //list contains no item

  itemRemoved = doubleLinkedListRemoveItemFromHead(&list);        //keep on removing item although no item left in list
  //test linked list
  TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved);                       //check that there is no item removed
  TEST_ASSERT_EQUAL_PTR(NULL, list.head);                         //check that head and tail do not point to any item
  TEST_ASSERT_EQUAL_PTR(NULL, list.tail);
  TEST_ASSERT_EQUAL(0, list.count);                               //check that the count remain zero
}

/*
  before (count = 1)

  list  |----> item1
        |
  head -|      next --->NULL
  tail         prev --->NULL
    |          ^ 10
    |__________|


  after (count = 0)

  list

  head --> NULL
  tail --> NULL

  remove item1 from head
  function returns item removed as item1

*/

//list has item1, after execute remove function, item1 is removed and returned by the function
void test_doubleLinkedListRemoveItemFromHead_given_list_containing_item1_expect_function_return_item_removed_as_item1() {
  ListItem* itemRemoved;
  ListItem item1 = {NULL, NULL, 10};
  DoubleLinkedList list = {&item1, &item1, 1};                    //list contains item1

  itemRemoved = doubleLinkedListRemoveItemFromHead(&list);        //remove item1 from head of list
  //test linked list
	TEST_ASSERT_EQUAL_PTR(&item1, itemRemoved);                     //check that the item removed is item 1
	TEST_ASSERT_EQUAL_PTR(NULL, list.head);
	TEST_ASSERT_EQUAL_PTR(NULL, list.tail);
	TEST_ASSERT_EQUAL(0, list.count);                               //check that the count is reduced by 1 after removing 1 item
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);                 //check that the item1.next and item1.prev points to null
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->prev);
	TEST_ASSERT_EQUAL(10, itemRemoved->data);
}

/*
  before (count = 2)

  list  |------> item2   |-----> item1
        |                |
  head -|         next --|        next-->NULL
  tail     NULL<--prev  <-------- prev
    |              20               ^ 10
    |_______________________________|


  after (count = 1)

  list  |----> item1
        |
  head -|      next --->NULL
  tail         prev --->NULL
    |          ^ 10
    |__________|

   remove item2 from head
   function returns item removed as item2

*/

//list has item1 and item2, after execute remove function, item2 is removed from head and returned by the function
void test_doubleLinkedListRemoveItemFromHead_given_list_containing_item1_and_item2_expect_function_return_item_removed_as_item2() {
  ListItem* itemRemoved;
  ListItem item1 = {NULL, NULL, 10};
  ListItem item2 = {NULL, NULL, 20};
  item1.prev = &item2;
  item2.next = &item1;
  DoubleLinkedList list = {&item2, &item1, 2};                    //list contains item1 and item2

  itemRemoved = doubleLinkedListRemoveItemFromHead(&list);        //remove item2 from head of list
  //test linked list
	TEST_ASSERT_EQUAL_PTR(&item2, itemRemoved);                     //check that the item removed is item 2
	TEST_ASSERT_EQUAL_PTR(&item1, list.head);
	TEST_ASSERT_EQUAL_PTR(&item1, list.tail);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.prev);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.next);
	TEST_ASSERT_EQUAL(1, list.count);                               //check that the count is reduced by 1 after removing 1 item
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);                 //check that the item2.next and item2.prev points to null
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->prev);
	TEST_ASSERT_EQUAL(20, itemRemoved->data);
}

/*
  before (count = 3)

  list  |------> item3   |-----> item2   |-----> item1
        |                |               |
  head -|         next --|        next --|        next --> NULL
  tail     NULL<--prev  <-------- prev  <-------- prev
    |              30              20              ^ 10
    |______________________________________________|


  after (count = 2)

  list  |------> item2   |-----> item1
        |                |
  head -|         next --|        next-->NULL
  tail     NULL<--prev  <-------- prev
    |              20               ^ 10
    |_______________________________|

  remove item3 from head
  function returns item removed as item3

*/

//list has item1, item2 and item3, after execute remove function, item3 is removed from head and returned by the function
void test_doubleLinkedListRemoveItemFromHead_given_list_containing_item1_item2_and_item3_expect_function_return_item_removed_as_item3() {
  ListItem* itemRemoved;
  ListItem item1 = {NULL, NULL, 10};
  ListItem item2 = {NULL, NULL, 20};
  ListItem item3 = {NULL, NULL, 30};
  item1.prev = &item2;
  item2.next = &item1;
  item2.prev = &item3;
  item3.next = &item2;
  DoubleLinkedList list = {&item3, &item1, 3};                    //list contains item1, item2 and item3

  itemRemoved = doubleLinkedListRemoveItemFromHead(&list);        //remove item3 from head of list
  //test linked list
	TEST_ASSERT_EQUAL_PTR(&item3, itemRemoved);                     //check that the item removed is item 3
	TEST_ASSERT_EQUAL_PTR(&item2, list.head);
	TEST_ASSERT_EQUAL_PTR(&item1, list.tail);
	TEST_ASSERT_EQUAL_PTR(NULL, item2.prev);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.next);
	TEST_ASSERT_EQUAL(2, list.count);                               //check that the count is reduced by 1 after removing 1 item
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);                 //check that the item3.next and item3.prev points to null
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->prev);
	TEST_ASSERT_EQUAL(30, itemRemoved->data);
}

//--------tests for doubleLinkedListRemoveItemFromTail----------------//

/*
  before (count = 0)

  list

  head --> NULL
  tail --> NULL

  after (count = 0)

  list

  head --> NULL
  tail --> NULL

  no changes as no item is removed
  the function return item removed as NULL

*/

//list has no item, after execute remove function, nothing is removed, list remains the same
void test_doubleLinkedListRemoveItemFromTail_given_empty_list_expect_function_return_item_removed_as_NULL() {
  ListItem* itemRemoved;
  DoubleLinkedList list = {NULL, NULL, 0};

  itemRemoved = doubleLinkedListRemoveItemFromTail(&list);
  //test linked list
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved);
	TEST_ASSERT_EQUAL_PTR(NULL, list.head);
	TEST_ASSERT_EQUAL_PTR(NULL, list.tail);
	TEST_ASSERT_EQUAL(0, list.count);
}

/*
  before (count = 1)

  list  |----> item1
        |
  head -|     next --->NULL
  tail        prev --->NULL
    |          ^ 10
    |__________|


  after (count = 0)

  list

  head --> NULL
  tail --> NULL

  remove item1 from tail
  function returns item removed as item1

*/

//list has item1, after execute remove function, item1 is removed and returned by the function
void test_doubleLinkedListRemoveItemFromTail_given_list_containing_item1_expect_function_return_item_removed_as_item1() {
  ListItem* itemRemoved;
  ListItem item1 = {NULL, NULL, 10};
  DoubleLinkedList list = {&item1, &item1, 1};

  itemRemoved = doubleLinkedListRemoveItemFromTail(&list);
  //test linked list
	TEST_ASSERT_EQUAL_PTR(&item1, itemRemoved);
	TEST_ASSERT_EQUAL_PTR(NULL, list.head);
	TEST_ASSERT_EQUAL_PTR(NULL, list.tail);
	TEST_ASSERT_EQUAL(0, list.count);
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->prev);
	TEST_ASSERT_EQUAL(10, itemRemoved->data);
}

/*
  before (count = 2)

  list    |---->  item1   |---->  item2
          |               |
  head ---|       next ---|       next-->NULL
  tail    NULL<---prev   <--------prev
    |              10              ^ 20
    |______________________________|

  after (count = 1)

  list  |----> item1
        |
  head -|     next --->NULL
  tail        prev --->NULL
    |          ^ 10
    |__________|

  remove item2 from tail
  function returns item removed as item2

*/

//list has item1 and item2, after execute remove function, item2 is removed from tail and returned by the function
void test_doubleLinkedListRemoveItemFromTail_given_list_containing_item1_and_item2_expect_function_return_item_removed_as_item2() {
  ListItem* itemRemoved;
  ListItem item1 = {NULL, NULL, 10};
  ListItem item2 = {NULL, NULL, 20};
  item1.next = &item2;
  item2.prev = &item1;
  DoubleLinkedList list = {&item1, &item2, 2};

  itemRemoved = doubleLinkedListRemoveItemFromTail(&list);
  //test linked list
	TEST_ASSERT_EQUAL_PTR(&item2, itemRemoved);
	TEST_ASSERT_EQUAL_PTR(&item1, list.tail);
	TEST_ASSERT_EQUAL_PTR(&item1, list.head);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.next);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.prev);
	TEST_ASSERT_EQUAL(1, list.count);
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->prev);
	TEST_ASSERT_EQUAL(20, itemRemoved->data);
}

/*
  before (count = 3)

  list    |---->  item1   |---->  item2   |---->  item3
          |               |               |
  head ---|       next ---|       next ---|        next --> NULL
  tail    NULL<---prev   <--------prev   <-------  prev
    |              10              20               ^ 30
    |_______________________________________________|

  after (count = 2)

  list    |---->  item1   |---->  item2
          |               |
  head ---|       next ---|       next-->NULL
  tail    NULL<---prev   <--------prev
    |              10              ^ 20
    |______________________________|

  remove item3 from tail
  function returns item removed as item3

*/

//list has item1, item2 and item3, after execute remove function, item3 is removed from tail and returned by the function
void test_doubleLinkedListRemoveItemFromTail_given_list_containing_item1_item2_and_item3_expect_function_return_item_removed_as_item3() {
  ListItem* itemRemoved;
  ListItem item1 = {NULL, NULL, 10};
  ListItem item2 = {NULL, NULL, 20};
  ListItem item3 = {NULL, NULL, 30};
  item1.next = &item2;
  item2.prev = &item1;
  item2.next = &item3;
  item3.prev = &item2;
  DoubleLinkedList list = {&item1, &item3, 3};

  itemRemoved = doubleLinkedListRemoveItemFromTail(&list);
  //test linked list
	TEST_ASSERT_EQUAL_PTR(&item3, itemRemoved);
	TEST_ASSERT_EQUAL_PTR(&item1, list.head);
	TEST_ASSERT_EQUAL_PTR(&item2, list.tail);
	TEST_ASSERT_EQUAL_PTR(NULL, item2.next);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.prev);
	TEST_ASSERT_EQUAL(2, list.count);
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->prev);
	TEST_ASSERT_EQUAL(30, itemRemoved->data);
}