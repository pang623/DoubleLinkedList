#include "build/temp/_test_DoubleLinkedList.c"
#include "src/DoubleLinkedList.h"
#include "C:/Ruby26-x64/lib/ruby/gems/2.6.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}

void test_doubleLinkedListAddItemToHead_given_item2_expect_head_points_item2_and_tail_points_item1_and_both_item1next_and_item2prev_points_to_null() {



 ListItem item1 = {

                  ((void *)0)

                      , 

                        ((void *)0)

                            , 10};

 ListItem item2 = {

                  ((void *)0)

                      , 

                        ((void *)0)

                            , 20};

 DoubleLinkedList list = {&item1, &item1, 1};



 int c = doubleLinkedListAddItemToHead(&list, &item2);



 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((item2.next)), (

((void *)0)

), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((item1.prev)), (

((void *)0)

), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item2.prev)), (

((void *)0)

), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item1.next)), (

((void *)0)

), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((c)), (

((void *)0)

), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((item1.data)), (

((void *)0)

), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((item2.data)), (

((void *)0)

), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListAddItemToTail_given_item2_expect_tail_points_item2_and_head_points_item1_and_both_item2next_and_item1prev_points_to_null() {



 ListItem item1 = {

                  ((void *)0)

                      , 

                        ((void *)0)

                            , 10};

 ListItem item2 = {

                  ((void *)0)

                      , 

                        ((void *)0)

                            , 20};

 DoubleLinkedList list = {&item1, &item1, 1};



 int c = doubleLinkedListAddItemToTail(&list, &item2);



 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(86), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((item1.next)), (

((void *)0)

), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((item2.prev)), (

((void *)0)

), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item1.prev)), (

((void *)0)

), (UNITY_UINT)(90), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item2.next)), (

((void *)0)

), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((c)), (

((void *)0)

), (UNITY_UINT)(92), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((item1.data)), (

((void *)0)

), (UNITY_UINT)(93), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((item2.data)), (

((void *)0)

), (UNITY_UINT)(94), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListRemoveItemFromHead_given_list_which_contains_no_item_expect_function_return_itemRemoved_as_NULL_and_head_and_tail_of_list_points_to_NULL() {

  ListItem* itemRemoved;

  DoubleLinkedList list = {

                          ((void *)0)

                              , 

                                ((void *)0)

                                    , 0};



  itemRemoved = doubleLinkedListRemoveItemFromHead(&list);



 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(126), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(127), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(128), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(129), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListRemoveItemFromHead_given_list_which_contains_item1_expect_function_return_itemRemoved_as_item1_and_head_and_tail_of_list_points_to_NULL() {

  ListItem* itemRemoved;

  ListItem item1 = {

                   ((void *)0)

                       , 

                         ((void *)0)

                             , 10};

  DoubleLinkedList list = {&item1, &item1, 1};



  itemRemoved = doubleLinkedListRemoveItemFromHead(&list);



 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(163), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(164), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(165), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(166), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(167), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(168), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(169), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListRemoveItemFromHead_given_list_which_contains_item1_and_item2_expect_function_return_itemRemoved_as_item2_and_head_and_tail_of_list_points_to_item1() {

  ListItem* itemRemoved;

  ListItem item1 = {

                   ((void *)0)

                       , 

                         ((void *)0)

                             , 10};

 ListItem item2 = {

                  ((void *)0)

                      , 

                        ((void *)0)

                            , 20};

  item1.prev = &item2;

  item2.next = &item1;

  DoubleLinkedList list = {&item2, &item1, 2};



  itemRemoved = doubleLinkedListRemoveItemFromHead(&list);



 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(208), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(209), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.tail)), (

 ((void *)0)

 ), (UNITY_UINT)(210), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item1.prev)), (

((void *)0)

), (UNITY_UINT)(211), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((

 ((void *)0)

 )), (UNITY_INT64)((item1.next)), (

 ((void *)0)

 ), (UNITY_UINT)(212), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(213), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(214), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(215), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(216), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListRemoveItemFromHead_given_list_which_contains_item1_item2_and_item3_expect_function_return_itemRemoved_as_item3_and_head_points_to_item2_tail_points_to_item1() {

  ListItem* itemRemoved;

  ListItem item1 = {

                   ((void *)0)

                       , 

                         ((void *)0)

                             , 10};

 ListItem item2 = {

                  ((void *)0)

                      , 

                        ((void *)0)

                            , 20};

  ListItem item3 = {

                   ((void *)0)

                       , 

                         ((void *)0)

                             , 30};

  item1.prev = &item2;

  item2.next = &item1;

  item2.prev = &item3;

  item3.next = &item2;

  DoubleLinkedList list = {&item3, &item1, 3};



  itemRemoved = doubleLinkedListRemoveItemFromHead(&list);



 UnityAssertEqualNumber((UNITY_INT64)((&item3)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(258), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(259), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.tail)), (

 ((void *)0)

 ), (UNITY_UINT)(260), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item2.prev)), (

((void *)0)

), (UNITY_UINT)(261), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((

 ((void *)0)

 )), (UNITY_INT64)((item1.next)), (

 ((void *)0)

 ), (UNITY_UINT)(262), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(263), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(264), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(265), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((30)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(266), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListRemoveItemFromTail_given_list_which_contains_no_item_expect_function_return_itemRemoved_as_NULL_and_head_and_tail_of_list_points_to_NULL() {

  ListItem* itemRemoved;

  DoubleLinkedList list = {

                          ((void *)0)

                              , 

                                ((void *)0)

                                    , 0};



  itemRemoved = doubleLinkedListRemoveItemFromTail(&list);



 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(298), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(299), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(300), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(301), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListRemoveItemFromTail_given_list_which_contains_item1_expect_function_return_itemRemoved_as_item1_and_head_and_tail_of_list_points_to_NULL() {

  ListItem* itemRemoved;

  ListItem item1 = {

                   ((void *)0)

                       , 

                         ((void *)0)

                             , 10};

  DoubleLinkedList list = {&item1, &item1, 1};



  itemRemoved = doubleLinkedListRemoveItemFromTail(&list);



 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(335), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(336), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(337), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(338), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(339), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(340), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(341), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListRemoveItemFromTail_given_list_which_contains_item1_and_item2_expect_function_return_itemRemoved_as_item2_and_head_and_tail_of_list_points_to_item1() {

  ListItem* itemRemoved;

  ListItem item1 = {

                   ((void *)0)

                       , 

                         ((void *)0)

                             , 10};

 ListItem item2 = {

                  ((void *)0)

                      , 

                        ((void *)0)

                            , 20};

  item1.next = &item2;

  item2.prev = &item1;

  DoubleLinkedList list = {&item1, &item2, 2};



  itemRemoved = doubleLinkedListRemoveItemFromTail(&list);



  UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((itemRemoved)), (

 ((void *)0)

 ), (UNITY_UINT)(379), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(380), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.head)), (

 ((void *)0)

 ), (UNITY_UINT)(381), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item1.next)), (

((void *)0)

), (UNITY_UINT)(382), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((

 ((void *)0)

 )), (UNITY_INT64)((item1.prev)), (

 ((void *)0)

 ), (UNITY_UINT)(383), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(384), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(385), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(386), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(387), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListRemoveItemFromTail_given_list_which_contains_item1_item2_and_item3_expect_function_return_itemRemoved_as_item3_and_head_points_to_item1_tail_points_to_item2() {

  ListItem* itemRemoved;

  ListItem item1 = {

                   ((void *)0)

                       , 

                         ((void *)0)

                             , 10};

 ListItem item2 = {

                  ((void *)0)

                      , 

                        ((void *)0)

                            , 20};

  ListItem item3 = {

                   ((void *)0)

                       , 

                         ((void *)0)

                             , 30};

  item1.next = &item2;

  item2.prev = &item1;

  item2.next = &item3;

  item3.prev = &item2;

  DoubleLinkedList list = {&item1, &item3, 3};



  itemRemoved = doubleLinkedListRemoveItemFromTail(&list);



  UnityAssertEqualNumber((UNITY_INT64)((&item3)), (UNITY_INT64)((itemRemoved)), (

 ((void *)0)

 ), (UNITY_UINT)(428), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.head)), (

 ((void *)0)

 ), (UNITY_UINT)(429), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(430), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item2.next)), (

((void *)0)

), (UNITY_UINT)(431), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((

 ((void *)0)

 )), (UNITY_INT64)((item1.prev)), (

 ((void *)0)

 ), (UNITY_UINT)(432), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(433), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(434), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(435), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((30)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(436), UNITY_DISPLAY_STYLE_INT);

}
