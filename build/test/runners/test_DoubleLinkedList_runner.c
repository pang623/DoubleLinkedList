/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_doubleLinkedListAddItemToHead_given_NULL_item_and_empty_list_expect_list_is_still_empty_after_adding();
extern void test_doubleLinkedListAddItemToHead_given_item1_and_empty_list_expect_item1_added_to_list();
extern void test_doubleLinkedListAddItemToHead_given_NULL_item_and_list_containing_an_item_expect_no_item_is_added_and_list_remains_the_same();
extern void test_doubleLinkedListAddItemToHead_given_item2_and_list_containing_item1_expect_item2_added_to_head_of_list();
extern void test_doubleLinkedListAddItemToHead_given_item3_and_list_containing_item1_and_item2_expect_item3_added_to_head_of_list();
extern void test_doubleLinkedListAddItemToTail_given_NULL_item_and_empty_list_expect_list_is_still_empty_after_adding();
extern void test_doubleLinkedListAddItemToTail_given_item1_and_empty_list_expect_item1_added_to_list();
extern void test_doubleLinkedListAddItemToTail_given_NULL_item_and_list_containing_an_item_expect_no_item_is_added_and_list_remains_the_same();
extern void test_doubleLinkedListAddItemToTail_given_item2_and_list_containing_item1_expect_item2_added_to_tail_of_list();
extern void test_doubleLinkedListAddItemToTail_given_item3_and_list_containing_item1_and_item2_expect_item3_added_to_tail_of_list();
extern void test_doubleLinkedListRemoveItemFromHead_given_empty_list_expect_function_return_item_removed_as_NULL();
extern void test_doubleLinkedListRemoveItemFromHead_given_list_containing_item1_expect_function_return_item_removed_as_item1();
extern void test_doubleLinkedListRemoveItemFromHead_given_list_containing_item1_and_item2_expect_function_return_item_removed_as_item2();
extern void test_doubleLinkedListRemoveItemFromHead_given_list_containing_item1_item2_and_item3_expect_function_return_item_removed_as_item3();
extern void test_doubleLinkedListRemoveItemFromTail_given_empty_list_expect_function_return_item_removed_as_NULL();
extern void test_doubleLinkedListRemoveItemFromTail_given_list_containing_item1_expect_function_return_item_removed_as_item1();
extern void test_doubleLinkedListRemoveItemFromTail_given_list_containing_item1_and_item2_expect_function_return_item_removed_as_item2();
extern void test_doubleLinkedListRemoveItemFromTail_given_list_containing_item1_item2_and_item3_expect_function_return_item_removed_as_item3();


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
}
static void CMock_Verify(void)
{
}
static void CMock_Destroy(void)
{
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, int line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_DoubleLinkedList.c");
  run_test(test_doubleLinkedListAddItemToHead_given_NULL_item_and_empty_list_expect_list_is_still_empty_after_adding, "test_doubleLinkedListAddItemToHead_given_NULL_item_and_empty_list_expect_list_is_still_empty_after_adding", 31);
  run_test(test_doubleLinkedListAddItemToHead_given_item1_and_empty_list_expect_item1_added_to_list, "test_doubleLinkedListAddItemToHead_given_item1_and_empty_list_expect_item1_added_to_list", 63);
  run_test(test_doubleLinkedListAddItemToHead_given_NULL_item_and_list_containing_an_item_expect_no_item_is_added_and_list_remains_the_same, "test_doubleLinkedListAddItemToHead_given_NULL_item_and_list_containing_an_item_expect_no_item_is_added_and_list_remains_the_same", 101);
  run_test(test_doubleLinkedListAddItemToHead_given_item2_and_list_containing_item1_expect_item2_added_to_head_of_list, "test_doubleLinkedListAddItemToHead_given_item2_and_list_containing_item1_expect_item2_added_to_head_of_list", 139);
  run_test(test_doubleLinkedListAddItemToHead_given_item3_and_list_containing_item1_and_item2_expect_item3_added_to_head_of_list, "test_doubleLinkedListAddItemToHead_given_item3_and_list_containing_item1_and_item2_expect_item3_added_to_head_of_list", 180);
  run_test(test_doubleLinkedListAddItemToTail_given_NULL_item_and_empty_list_expect_list_is_still_empty_after_adding, "test_doubleLinkedListAddItemToTail_given_NULL_item_and_empty_list_expect_list_is_still_empty_after_adding", 226);
  run_test(test_doubleLinkedListAddItemToTail_given_item1_and_empty_list_expect_item1_added_to_list, "test_doubleLinkedListAddItemToTail_given_item1_and_empty_list_expect_item1_added_to_list", 258);
  run_test(test_doubleLinkedListAddItemToTail_given_NULL_item_and_list_containing_an_item_expect_no_item_is_added_and_list_remains_the_same, "test_doubleLinkedListAddItemToTail_given_NULL_item_and_list_containing_an_item_expect_no_item_is_added_and_list_remains_the_same", 296);
  run_test(test_doubleLinkedListAddItemToTail_given_item2_and_list_containing_item1_expect_item2_added_to_tail_of_list, "test_doubleLinkedListAddItemToTail_given_item2_and_list_containing_item1_expect_item2_added_to_tail_of_list", 334);
  run_test(test_doubleLinkedListAddItemToTail_given_item3_and_list_containing_item1_and_item2_expect_item3_added_to_tail_of_list, "test_doubleLinkedListAddItemToTail_given_item3_and_list_containing_item1_and_item2_expect_item3_added_to_tail_of_list", 374);
  run_test(test_doubleLinkedListRemoveItemFromHead_given_empty_list_expect_function_return_item_removed_as_NULL, "test_doubleLinkedListRemoveItemFromHead_given_empty_list_expect_function_return_item_removed_as_NULL", 422);
  run_test(test_doubleLinkedListRemoveItemFromHead_given_list_containing_item1_expect_function_return_item_removed_as_item1, "test_doubleLinkedListRemoveItemFromHead_given_list_containing_item1_expect_function_return_item_removed_as_item1", 458);
  run_test(test_doubleLinkedListRemoveItemFromHead_given_list_containing_item1_and_item2_expect_function_return_item_removed_as_item2, "test_doubleLinkedListRemoveItemFromHead_given_list_containing_item1_and_item2_expect_function_return_item_removed_as_item2", 500);
  run_test(test_doubleLinkedListRemoveItemFromHead_given_list_containing_item1_item2_and_item3_expect_function_return_item_removed_as_item3, "test_doubleLinkedListRemoveItemFromHead_given_list_containing_item1_item2_and_item3_expect_function_return_item_removed_as_item3", 547);
  run_test(test_doubleLinkedListRemoveItemFromTail_given_empty_list_expect_function_return_item_removed_as_NULL, "test_doubleLinkedListRemoveItemFromTail_given_empty_list_expect_function_return_item_removed_as_NULL", 594);
  run_test(test_doubleLinkedListRemoveItemFromTail_given_list_containing_item1_expect_function_return_item_removed_as_item1, "test_doubleLinkedListRemoveItemFromTail_given_list_containing_item1_expect_function_return_item_removed_as_item1", 630);
  run_test(test_doubleLinkedListRemoveItemFromTail_given_list_containing_item1_and_item2_expect_function_return_item_removed_as_item2, "test_doubleLinkedListRemoveItemFromTail_given_list_containing_item1_and_item2_expect_function_return_item_removed_as_item2", 671);
  run_test(test_doubleLinkedListRemoveItemFromTail_given_list_containing_item1_item2_and_item3_expect_function_return_item_removed_as_item3, "test_doubleLinkedListRemoveItemFromTail_given_list_containing_item1_item2_and_item3_expect_function_return_item_removed_as_item3", 717);

  return UnityEnd();
}
