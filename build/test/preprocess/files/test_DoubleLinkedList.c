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

), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((item2.next)), (

((void *)0)

), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((item1.prev)), (

((void *)0)

), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item2.prev)), (

((void *)0)

), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item1.next)), (

((void *)0)

), (UNITY_UINT)(26), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((c)), (

((void *)0)

), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((item1.data)), (

((void *)0)

), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((item2.data)), (

((void *)0)

), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_INT);

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

), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((item1.next)), (

((void *)0)

), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((item2.prev)), (

((void *)0)

), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item1.prev)), (

((void *)0)

), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item2.next)), (

((void *)0)

), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((c)), (

((void *)0)

), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((item1.data)), (

((void *)0)

), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((item2.data)), (

((void *)0)

), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_INT);

}



void test_doubleLinkedListRemoveItemFromHead_given_list_expect_lastItem_to_be_removed_from_head_of_linked_list_every_time_the_function_is_executed_item_removed_in_order_of_321() {



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

 DoubleLinkedList list = {&item1, &item1, 1};



 doubleLinkedListAddItemToHead(&list, &item2);



 doubleLinkedListAddItemToHead(&list, &item3);









 itemRemoved = doubleLinkedListRemoveItemFromHead(&list);



 UnityAssertEqualNumber((UNITY_INT64)((&item3)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item2.prev)), (

((void *)0)

), (UNITY_UINT)(70), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(73), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((30)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(74), UNITY_DISPLAY_STYLE_INT);



 itemRemoved = doubleLinkedListRemoveItemFromHead(&list);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item1.prev)), (

((void *)0)

), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_INT);



 itemRemoved = doubleLinkedListRemoveItemFromHead(&list);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(86), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(88), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(90), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(92), UNITY_DISPLAY_STYLE_INT);















 itemRemoved = doubleLinkedListRemoveItemFromHead(&list);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(101), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(102), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(103), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(104), UNITY_DISPLAY_STYLE_INT);

}



void test_doubleLinkedListRemoveItemFromHead_given_list_expect_lastItem_to_be_removed_from_head_of_linked_list_every_time_the_function_is_executed_item_removed_in_order_of_123() {



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

 DoubleLinkedList list = {&item1, &item1, 1};



 doubleLinkedListAddItemToTail(&list, &item2);



 doubleLinkedListAddItemToTail(&list, &item3);









 itemRemoved = doubleLinkedListRemoveItemFromHead(&list);



 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(124), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(125), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item2.prev)), (

((void *)0)

), (UNITY_UINT)(126), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(127), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(128), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(129), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(130), UNITY_DISPLAY_STYLE_INT);



 itemRemoved = doubleLinkedListRemoveItemFromHead(&list);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(133), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item3)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(134), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item3.prev)), (

((void *)0)

), (UNITY_UINT)(135), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(136), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(137), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(138), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(139), UNITY_DISPLAY_STYLE_INT);



 itemRemoved = doubleLinkedListRemoveItemFromHead(&list);

 UnityAssertEqualNumber((UNITY_INT64)((&item3)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(142), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(143), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(144), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(145), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(146), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(147), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((30)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(148), UNITY_DISPLAY_STYLE_INT);















 itemRemoved = doubleLinkedListRemoveItemFromHead(&list);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(157), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(158), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(159), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(160), UNITY_DISPLAY_STYLE_INT);

}



void test_doubleLinkedListRemoveItemFromTail_given_list_expect_lastItem_to_be_removed_from_tail_of_linked_list_every_time_the_function_is_executed_item_removed_in_order_of_321() {



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

 DoubleLinkedList list = {&item1, &item1, 1};



 doubleLinkedListAddItemToTail(&list, &item2);



 doubleLinkedListAddItemToTail(&list, &item3);









 itemRemoved = doubleLinkedListRemoveItemFromTail(&list);



 UnityAssertEqualNumber((UNITY_INT64)((&item3)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(180), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(181), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item2.next)), (

((void *)0)

), (UNITY_UINT)(182), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(183), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(184), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(185), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((30)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(186), UNITY_DISPLAY_STYLE_INT);



 itemRemoved = doubleLinkedListRemoveItemFromTail(&list);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(189), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(190), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item1.next)), (

((void *)0)

), (UNITY_UINT)(191), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(192), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(193), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(194), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(195), UNITY_DISPLAY_STYLE_INT);



 itemRemoved = doubleLinkedListRemoveItemFromTail(&list);

 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(198), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(199), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(200), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(201), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(202), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(203), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(204), UNITY_DISPLAY_STYLE_INT);















 itemRemoved = doubleLinkedListRemoveItemFromTail(&list);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(213), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(214), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(215), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(216), UNITY_DISPLAY_STYLE_INT);

}







void test_doubleLinkedListRemoveItemFromTail_given_list_expect_lastItem_to_be_removed_from_tail_of_linked_list_every_time_the_function_is_executed_item_removed_in_order_of_123() {



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

 DoubleLinkedList list = {&item1, &item1, 1};



 doubleLinkedListAddItemToHead(&list, &item2);



 doubleLinkedListAddItemToHead(&list, &item3);









 itemRemoved = doubleLinkedListRemoveItemFromTail(&list);



 UnityAssertEqualNumber((UNITY_INT64)((&item1)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(238), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(239), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item2.next)), (

((void *)0)

), (UNITY_UINT)(240), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(241), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(242), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(243), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(244), UNITY_DISPLAY_STYLE_INT);



 itemRemoved = doubleLinkedListRemoveItemFromTail(&list);

 UnityAssertEqualNumber((UNITY_INT64)((&item2)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(247), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((&item3)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(248), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((item3.next)), (

((void *)0)

), (UNITY_UINT)(249), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(250), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(251), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(252), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((20)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(253), UNITY_DISPLAY_STYLE_INT);



 itemRemoved = doubleLinkedListRemoveItemFromTail(&list);

 UnityAssertEqualNumber((UNITY_INT64)((&item3)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(256), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(257), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(258), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(259), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->next)), (

((void *)0)

), (UNITY_UINT)(260), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved->prev)), (

((void *)0)

), (UNITY_UINT)(261), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((30)), (UNITY_INT)((itemRemoved->data)), (

((void *)0)

), (UNITY_UINT)(262), UNITY_DISPLAY_STYLE_INT);















 itemRemoved = doubleLinkedListRemoveItemFromTail(&list);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((itemRemoved)), (

((void *)0)

), (UNITY_UINT)(271), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.head)), (

((void *)0)

), (UNITY_UINT)(272), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT64)((

((void *)0)

)), (UNITY_INT64)((list.tail)), (

((void *)0)

), (UNITY_UINT)(273), UNITY_DISPLAY_STYLE_HEX64);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((list.count)), (

((void *)0)

), (UNITY_UINT)(274), UNITY_DISPLAY_STYLE_INT);

}
