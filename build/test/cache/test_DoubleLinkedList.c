#include "build/temp/_test_DoubleLinkedList.c"
#include "src/DoubleLinkedList.h"
#include "C:/Ruby26-x64/lib/ruby/gems/2.6.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}

void test_doubleLinkedListAddItemToHead_given_NULL_item_and_empty_list_expect_list_is_still_empty_after_adding() {



 DoubleLinkedList list = {

                         ((void *)0)

                             , 

                               ((void *)0)

                                   , 0};



 int count = doubleLinkedListAddItemToHead(&list, 

                                                 ((void *)0)

                                                     );



 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((count)), (

((void *)0)

), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListAddItemToHead_given_item1_and_empty_list_expect_item1_added_to_list() {



  ListItem item1 = {

                   ((void *)0)

                       , 

                         ((void *)0)

                             , 10};

 DoubleLinkedList list = {

                         ((void *)0)

                             , 

                               ((void *)0)

                                   , 0};



 int count = doubleLinkedListAddItemToHead(&list, &item1);



 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(70), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((

 ((void *)0)

 )), (UNITY_INT64)((item1.next)), (

 ((void *)0)

 ), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item1.prev)), (

((void *)0)

), (UNITY_UINT)(73), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((item1.data)), (

 ((void *)0)

 ), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((count)), (

((void *)0)

), (UNITY_UINT)(75), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListAddItemToHead_given_NULL_item_and_list_containing_an_item_expect_no_item_is_added_and_list_remains_the_same() {



  ListItem item1 = {

                   ((void *)0)

                       , 

                         ((void *)0)

                             , 10};

 DoubleLinkedList list = {&item1, &item1, 1};



 int count = doubleLinkedListAddItemToHead(&list, 

                                                 ((void *)0)

                                                     );



 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(108), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(109), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((

 ((void *)0)

 )), (UNITY_INT64)((item1.next)), (

 ((void *)0)

 ), (UNITY_UINT)(110), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item1.prev)), (

((void *)0)

), (UNITY_UINT)(111), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((item1.data)), (

 ((void *)0)

 ), (UNITY_UINT)(112), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((count)), (

((void *)0)

), (UNITY_UINT)(113), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListAddItemToHead_given_item2_and_list_containing_item1_expect_item2_added_to_head_of_list() {



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



 int count = doubleLinkedListAddItemToHead(&list, &item2);



 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(147), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(148), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((item2.next)), (

((void *)0)

), (UNITY_UINT)(149), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((item1.prev)), (

((void *)0)

), (UNITY_UINT)(150), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item2.prev)), (

((void *)0)

), (UNITY_UINT)(151), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item1.next)), (

((void *)0)

), (UNITY_UINT)(152), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((count)), (

((void *)0)

), (UNITY_UINT)(153), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((item1.data)), (

((void *)0)

), (UNITY_UINT)(154), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((item2.data)), (

((void *)0)

), (UNITY_UINT)(155), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListAddItemToHead_given_item3_and_list_containing_item1_and_item2_expect_item3_added_to_head_of_list() {



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

 DoubleLinkedList list = {&item2, &item1, 2};



 int count = doubleLinkedListAddItemToHead(&list, &item3);



 UnityAssertEqualNumber((UNITY_INT64)((&item3)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(191), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(192), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((item3.next)), (

 ((void *)0)

 ), (UNITY_UINT)(193), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((

 ((void *)0)

 )), (UNITY_INT64)((item3.prev)), (

 ((void *)0)

 ), (UNITY_UINT)(194), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((item2.next)), (

((void *)0)

), (UNITY_UINT)(195), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((&item3)), (UNITY_INT64)((item2.prev)), (

 ((void *)0)

 ), (UNITY_UINT)(196), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((

 ((void *)0)

 )), (UNITY_INT64)((item1.next)), (

 ((void *)0)

 ), (UNITY_UINT)(197), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((item1.prev)), (

((void *)0)

), (UNITY_UINT)(198), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((count)), (

((void *)0)

), (UNITY_UINT)(199), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((item1.data)), (

((void *)0)

), (UNITY_UINT)(200), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((item2.data)), (

((void *)0)

), (UNITY_UINT)(201), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((30)), (UNITY_INT)((item3.data)), (

 ((void *)0)

 ), (UNITY_UINT)(202), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListAddItemToTail_given_NULL_item_and_empty_list_expect_list_is_still_empty_after_adding() {



 DoubleLinkedList list = {

                         ((void *)0)

                             , 

                               ((void *)0)

                                   , 0};



 int count = doubleLinkedListAddItemToTail(&list, 

                                                 ((void *)0)

                                                     );



 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(232), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(233), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((count)), (

((void *)0)

), (UNITY_UINT)(234), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListAddItemToTail_given_item1_and_empty_list_expect_item1_added_to_list() {



  ListItem item1 = {

                   ((void *)0)

                       , 

                         ((void *)0)

                             , 10};

 DoubleLinkedList list = {

                         ((void *)0)

                             , 

                               ((void *)0)

                                   , 0};



 int count = doubleLinkedListAddItemToTail(&list, &item1);



 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(265), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(266), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((

 ((void *)0)

 )), (UNITY_INT64)((item1.next)), (

 ((void *)0)

 ), (UNITY_UINT)(267), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item1.prev)), (

((void *)0)

), (UNITY_UINT)(268), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((item1.data)), (

 ((void *)0)

 ), (UNITY_UINT)(269), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((count)), (

((void *)0)

), (UNITY_UINT)(270), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListAddItemToTail_given_NULL_item_and_list_containing_an_item_expect_no_item_is_added_and_list_remains_the_same() {



  ListItem item1 = {

                   ((void *)0)

                       , 

                         ((void *)0)

                             , 10};

 DoubleLinkedList list = {&item1, &item1, 1};



 int count = doubleLinkedListAddItemToTail(&list, 

                                                 ((void *)0)

                                                     );



 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(303), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(304), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((

 ((void *)0)

 )), (UNITY_INT64)((item1.next)), (

 ((void *)0)

 ), (UNITY_UINT)(305), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item1.prev)), (

((void *)0)

), (UNITY_UINT)(306), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((item1.data)), (

 ((void *)0)

 ), (UNITY_UINT)(307), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((count)), (

((void *)0)

), (UNITY_UINT)(308), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListAddItemToTail_given_item2_and_list_containing_item1_expect_item2_added_to_tail_of_list() {



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



 int count = doubleLinkedListAddItemToTail(&list, &item2);



 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(342), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(343), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((

 ((void *)0)

 )), (UNITY_INT64)((item1.prev)), (

 ((void *)0)

 ), (UNITY_UINT)(344), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((item1.next)), (

((void *)0)

), (UNITY_UINT)(345), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((item2.prev)), (

 ((void *)0)

 ), (UNITY_UINT)(346), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((

 ((void *)0)

 )), (UNITY_INT64)((item2.next)), (

 ((void *)0)

 ), (UNITY_UINT)(347), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((count)), (

((void *)0)

), (UNITY_UINT)(348), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((item1.data)), (

((void *)0)

), (UNITY_UINT)(349), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((item2.data)), (

((void *)0)

), (UNITY_UINT)(350), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListAddItemToTail_given_item3_and_list_containing_item1_and_item2_expect_item3_added_to_tail_of_list() {



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

 DoubleLinkedList list = {&item1, &item2, 2};



 int count = doubleLinkedListAddItemToTail(&list, &item3);



 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(385), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item3)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(386), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((

 ((void *)0)

 )), (UNITY_INT64)((item3.next)), (

 ((void *)0)

 ), (UNITY_UINT)(387), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((item3.prev)), (

 ((void *)0)

 ), (UNITY_UINT)(388), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item3)), (UNITY_INT64)((item2.next)), (

((void *)0)

), (UNITY_UINT)(389), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((item2.prev)), (

 ((void *)0)

 ), (UNITY_UINT)(390), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((item1.next)), (

 ((void *)0)

 ), (UNITY_UINT)(391), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item1.prev)), (

((void *)0)

), (UNITY_UINT)(392), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((3)), (UNITY_INT)((count)), (

((void *)0)

), (UNITY_UINT)(393), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((item1.data)), (

((void *)0)

), (UNITY_UINT)(394), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((item2.data)), (

((void *)0)

), (UNITY_UINT)(395), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((30)), (UNITY_INT)((item3.data)), (

 ((void *)0)

 ), (UNITY_UINT)(396), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListRemoveItemFromHead_given_empty_list_expect_function_return_item_removed_as_NULL() {

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

 ), (UNITY_UINT)(428), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((

 ((void *)0)

 )), (UNITY_INT64)((list.head)), (

 ((void *)0)

 ), (UNITY_UINT)(429), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT64)((

 ((void *)0)

 )), (UNITY_INT64)((list.tail)), (

 ((void *)0)

 ), (UNITY_UINT)(430), UNITY_DISPLAY_STYLE_HEX64);

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list.count)), (

 ((void *)0)

 ), (UNITY_UINT)(431), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListRemoveItemFromHead_given_list_containing_item1_expect_function_return_item_removed_as_item1() {

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

), (UNITY_UINT)(465), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(466), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(467), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(468), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(469), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(470), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(471), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListRemoveItemFromHead_given_list_containing_item1_and_item2_expect_function_return_item_removed_as_item2() {

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

), (UNITY_UINT)(510), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(511), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(512), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item1.prev)), (

((void *)0)

), (UNITY_UINT)(513), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item1.next)), (

((void *)0)

), (UNITY_UINT)(514), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(515), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(516), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(517), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(518), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListRemoveItemFromHead_given_list_containing_item1_item2_and_item3_expect_function_return_item_removed_as_item3() {

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

), (UNITY_UINT)(560), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(561), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(562), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item2.prev)), (

((void *)0)

), (UNITY_UINT)(563), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item1.next)), (

((void *)0)

), (UNITY_UINT)(564), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(565), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(566), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(567), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((30)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(568), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListRemoveItemFromTail_given_empty_list_expect_function_return_item_removed_as_NULL() {

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

), (UNITY_UINT)(600), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(601), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(602), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(603), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListRemoveItemFromTail_given_list_containing_item1_expect_function_return_item_removed_as_item1() {

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

), (UNITY_UINT)(637), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(638), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(639), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(640), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(641), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(642), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(643), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListRemoveItemFromTail_given_list_containing_item1_and_item2_expect_function_return_item_removed_as_item2() {

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

), (UNITY_UINT)(681), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(682), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(683), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item1.next)), (

((void *)0)

), (UNITY_UINT)(684), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item1.prev)), (

((void *)0)

), (UNITY_UINT)(685), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(686), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(687), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(688), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(689), UNITY_DISPLAY_STYLE_INT);

}

void test_doubleLinkedListRemoveItemFromTail_given_list_containing_item1_item2_and_item3_expect_function_return_item_removed_as_item3() {

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

), (UNITY_UINT)(730), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(731), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(732), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item2.next)), (

((void *)0)

), (UNITY_UINT)(733), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item1.prev)), (

((void *)0)

), (UNITY_UINT)(734), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(735), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(736), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(737), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((30)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(738), UNITY_DISPLAY_STYLE_INT);

}
