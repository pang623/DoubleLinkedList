#include "unity.h"
#include "DoubleLinkedList.h"

void setUp(void)
{
}

void tearDown(void)
{
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

void test_doubleLinkedListAddItemToHead_given_item2_expect_head_points_item2_and_tail_points_item1_and_both_item1next_and_item2prev_points_to_null() {
	//initialise items and list
	ListItem item1 = {NULL, NULL, 10};
	ListItem item2 = {NULL, NULL, 20};
	DoubleLinkedList list = {&item1, &item1, 1};              //item1 had been added to linked list, this way of adding item can only be done when the list does not has any item
	//add item 2 to head
	int c = doubleLinkedListAddItemToHead(&list, &item2);
	//test the linked list
	TEST_ASSERT_EQUAL_PTR(&item2, list.head);
	TEST_ASSERT_EQUAL_PTR(&item1, list.tail);
	TEST_ASSERT_EQUAL_PTR(&item1, item2.next);
	TEST_ASSERT_EQUAL_PTR(&item2, item1.prev);
	TEST_ASSERT_EQUAL_PTR(NULL, item2.prev);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.next);
	TEST_ASSERT_EQUAL(2, c);                                  //check that the count has incremented by one after adding 1 item
	TEST_ASSERT_EQUAL(10, item1.data);
	TEST_ASSERT_EQUAL(20, item2.data);
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

void test_doubleLinkedListAddItemToTail_given_item2_expect_tail_points_item2_and_head_points_item1_and_both_item2next_and_item1prev_points_to_null() {
	//initialise items and list
	ListItem item1 = {NULL, NULL, 10};
	ListItem item2 = {NULL, NULL, 20};
	DoubleLinkedList list = {&item1, &item1, 1};              //item1 had been added to linked list
	//add item 2 to tail
	int c = doubleLinkedListAddItemToTail(&list, &item2);
	//test the linked list
	TEST_ASSERT_EQUAL_PTR(&item1, list.head);
	TEST_ASSERT_EQUAL_PTR(&item2, list.tail);
	TEST_ASSERT_EQUAL_PTR(&item2, item1.next);
	TEST_ASSERT_EQUAL_PTR(&item1, item2.prev);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.prev);
	TEST_ASSERT_EQUAL_PTR(NULL, item2.next);
	TEST_ASSERT_EQUAL(2, c);                                  //check that the count has incremented by one after adding 1 item
	TEST_ASSERT_EQUAL(10, item1.data);
	TEST_ASSERT_EQUAL(20, item2.data);
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
void test_doubleLinkedListRemoveItemFromHead_given_list_which_contains_no_item_expect_function_return_itemRemoved_as_NULL_and_head_and_tail_of_list_points_to_NULL() {
  ListItem* itemRemoved;
  DoubleLinkedList list = {NULL, NULL, 0};                        //list contains no item

  itemRemoved = doubleLinkedListRemoveItemFromHead(&list);        //keep on removing item although no item left in list
  //test linked list
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved);                 //check that there is no item removed
	TEST_ASSERT_EQUAL_PTR(NULL, list.head);                   //check that head and tail do not point to any item
	TEST_ASSERT_EQUAL_PTR(NULL, list.tail);
	TEST_ASSERT_EQUAL(0, list.count);                         //check that the count remain zero
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
void test_doubleLinkedListRemoveItemFromHead_given_list_which_contains_item1_expect_function_return_itemRemoved_as_item1_and_head_and_tail_of_list_points_to_NULL() {
  ListItem* itemRemoved;
  ListItem item1 = {NULL, NULL, 10};
  DoubleLinkedList list = {&item1, &item1, 1};                    //list contains item1

  itemRemoved = doubleLinkedListRemoveItemFromHead(&list);        //remove item1 from head of list
  //test linked list
	TEST_ASSERT_EQUAL_PTR(&item1, itemRemoved);               //check that the item removed is item 1
	TEST_ASSERT_EQUAL_PTR(NULL, list.head);
	TEST_ASSERT_EQUAL_PTR(NULL, list.tail);
	TEST_ASSERT_EQUAL(0, list.count);                         //check that the count is reduced by 1 after removing 1 item
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);           //check that the item1.next and item1.prev points to null
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
void test_doubleLinkedListRemoveItemFromHead_given_list_which_contains_item1_and_item2_expect_function_return_itemRemoved_as_item2_and_head_and_tail_of_list_points_to_item1() {
  ListItem* itemRemoved;
  ListItem item1 = {NULL, NULL, 10};
  ListItem item2 = {NULL, NULL, 20};
  item1.prev = &item2;
  item2.next = &item1;
  DoubleLinkedList list = {&item2, &item1, 2};                    //list contains item1 and item2

  itemRemoved = doubleLinkedListRemoveItemFromHead(&list);        //remove item2 from head of list
  //test linked list
	TEST_ASSERT_EQUAL_PTR(&item2, itemRemoved);               //check that the item removed is item 2
	TEST_ASSERT_EQUAL_PTR(&item1, list.head);
	TEST_ASSERT_EQUAL_PTR(&item1, list.tail);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.prev);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.next);
	TEST_ASSERT_EQUAL(1, list.count);                         //check that the count is reduced by 1 after removing 1 item
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);           //check that the item2.next and item2.prev points to null
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
void test_doubleLinkedListRemoveItemFromHead_given_list_which_contains_item1_item2_and_item3_expect_function_return_itemRemoved_as_item3_and_head_points_to_item2_tail_points_to_item1() {
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
	TEST_ASSERT_EQUAL_PTR(&item3, itemRemoved);               //check that the item removed is item 3
	TEST_ASSERT_EQUAL_PTR(&item2, list.head);
	TEST_ASSERT_EQUAL_PTR(&item1, list.tail);
	TEST_ASSERT_EQUAL_PTR(NULL, item2.prev);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.next);
	TEST_ASSERT_EQUAL(2, list.count);                         //check that the count is reduced by 1 after removing 1 item
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);           //check that the item3.next and item3.prev points to null
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
void test_doubleLinkedListRemoveItemFromTail_given_list_which_contains_no_item_expect_function_return_itemRemoved_as_NULL_and_head_and_tail_of_list_points_to_NULL() {
  ListItem* itemRemoved;
  DoubleLinkedList list = {NULL, NULL, 0};                        //list contains no item

  itemRemoved = doubleLinkedListRemoveItemFromTail(&list);        //keep on removing item although no item left in list
  //test linked list
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved);                 //check that there is no item removed
	TEST_ASSERT_EQUAL_PTR(NULL, list.head);                   //check that head and tail do not point to any item
	TEST_ASSERT_EQUAL_PTR(NULL, list.tail);
	TEST_ASSERT_EQUAL(0, list.count);                         //check that the count remain zero
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
void test_doubleLinkedListRemoveItemFromTail_given_list_which_contains_item1_expect_function_return_itemRemoved_as_item1_and_head_and_tail_of_list_points_to_NULL() {
  ListItem* itemRemoved;
  ListItem item1 = {NULL, NULL, 10};
  DoubleLinkedList list = {&item1, &item1, 1};                    //list contains item1

  itemRemoved = doubleLinkedListRemoveItemFromTail(&list);        //remove item1 from tail of list
  //test linked list
	TEST_ASSERT_EQUAL_PTR(&item1, itemRemoved);               //check that the item removed is item 1
	TEST_ASSERT_EQUAL_PTR(NULL, list.head);
	TEST_ASSERT_EQUAL_PTR(NULL, list.tail);
	TEST_ASSERT_EQUAL(0, list.count);                         //check that the count is reduced by 1 after removing 1 item
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);           //check that the item1.next and item1.prev points to null
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
void test_doubleLinkedListRemoveItemFromTail_given_list_which_contains_item1_and_item2_expect_function_return_itemRemoved_as_item2_and_head_and_tail_of_list_points_to_item1() {
  ListItem* itemRemoved;
  ListItem item1 = {NULL, NULL, 10};
  ListItem item2 = {NULL, NULL, 20};
  item1.next = &item2;
  item2.prev = &item1;
  DoubleLinkedList list = {&item1, &item2, 2};                    //list contains item1 and item2

  itemRemoved = doubleLinkedListRemoveItemFromTail(&list);        //remove item2 from tail of list
  //test linked list
	TEST_ASSERT_EQUAL_PTR(&item2, itemRemoved);               //check that the item removed is item 2
	TEST_ASSERT_EQUAL_PTR(&item1, list.tail);
	TEST_ASSERT_EQUAL_PTR(&item1, list.head);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.next);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.prev);
	TEST_ASSERT_EQUAL(1, list.count);                         //check that the count is reduced by 1 after removing 1 item
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);           //check that the item2.next and item2.prev points to null
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
void test_doubleLinkedListRemoveItemFromTail_given_list_which_contains_item1_item2_and_item3_expect_function_return_itemRemoved_as_item3_and_head_points_to_item1_tail_points_to_item2() {
  ListItem* itemRemoved;
  ListItem item1 = {NULL, NULL, 10};
  ListItem item2 = {NULL, NULL, 20};
  ListItem item3 = {NULL, NULL, 30};
  item1.next = &item2;
  item2.prev = &item1;
  item2.next = &item3;
  item3.prev = &item2;
  DoubleLinkedList list = {&item1, &item3, 3};                    //list contains item1, item2 and item3

  itemRemoved = doubleLinkedListRemoveItemFromTail(&list);        //remove item3 from tail of list
  //test linked list
	TEST_ASSERT_EQUAL_PTR(&item3, itemRemoved);               //check that the item removed is item 3
	TEST_ASSERT_EQUAL_PTR(&item1, list.head);
	TEST_ASSERT_EQUAL_PTR(&item2, list.tail);
	TEST_ASSERT_EQUAL_PTR(NULL, item2.next);
	TEST_ASSERT_EQUAL_PTR(NULL, item1.prev);
	TEST_ASSERT_EQUAL(2, list.count);                         //check that the count is reduced by 1 after removing 1 item
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->next);           //check that the item3.next and item3.prev points to null
	TEST_ASSERT_EQUAL_PTR(NULL, itemRemoved->prev);
	TEST_ASSERT_EQUAL(30, itemRemoved->data);
}
