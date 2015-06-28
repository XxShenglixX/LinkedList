#include "unity.h"
#include <stdint.h>
#include <malloc.h>
#include "LinkedList.h"
#include "List_Utilities.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_checkIsListNull_should_return_1_if_is_NULL()
{
	LinkedList *list = NULL ;
	
	TEST_ASSERT_EQUAL(1,checkIsListNull(list));
}

void test_checkIsListNull_should_return_0_if_is_not_NULL()
{
	LinkedList *list = listCreate(0x200) ;
	
	TEST_ASSERT_EQUAL(0,checkIsListNull(list));
	listDestroy(list);
}

void test_checkIsListMatchTarget_should_return_1_if_both_are_the_same()
{
	LinkedList *list = listCreate(0x200) ;
	
	TEST_ASSERT_EQUAL(1,checkIsListMatchTarget(list,list));

	listDestroy(list);

}

void test_checkIsListMatchTarget_should_return_0_if_both_are_not_the_same()
{
	LinkedList *list = listCreate(0x200) ;
	LinkedList *list1 = listCreate(0x200) ;
	
	TEST_ASSERT_EQUAL(0,checkIsListMatchTarget(list,list1));

	listDestroy(list);
}

void test_setHead_to_list_should_set_Head_to_the_target_List()
{
	LinkedList *list = listCreate(0x200) ;
	LinkedList *Head ;
	
	setHead(&Head,list);
	TEST_ASSERT_EQUAL(list,Head);
	
	listDestroy(list);
}

void test_setHead_to_NULL_should_set_Head_to_NULL()
{
	LinkedList *Head ;
	
	setHead(&Head,NULL);
	TEST_ASSERT_NULL(Head);
	
}

void test_setTail__to_list_should_set_Tail_to_the_target_List()
{
	LinkedList *list = listCreate(0x200) ;
	LinkedList *Tail ;
	
	setTail(&Tail,list);
	TEST_ASSERT_EQUAL(list,Tail);
	
	listDestroy(list);
}

void test_travel_1step_beforeTarget_given_3_element_list_target_Tail_should_return_list_1()
{
	LinkedList *list0 = listCreate(0x100);
	LinkedList *list1 = listCreate(0x200);
	LinkedList *list2 = listCreate(0x300);
	LinkedList *Head,*Tail, *Target ;
	
	listAddHead(&Head,list0);
	setTail(&Tail,list0);
	listAddTail(&Tail,list1);
	listAddTail(&Tail,list2);
	
	Target = travel_1step_beforeTarget(Head,Tail);
	
	TEST_ASSERT_EQUAL(list1,Target);

}

void test_travel_1step_beforeTarget_given_3_element_list_target_list1_should_return_list_0()
{
	LinkedList *list0 = listCreate(0x100);
	LinkedList *list1 = listCreate(0x200);
	LinkedList *list2 = listCreate(0x300);
	LinkedList *Head,*Tail, *Target ;
	
	listAddHead(&Head,list0);
	setTail(&Tail,Head);
	listAddTail(&Tail,list1);
	listAddTail(&Tail,list2);
	
	Target = travel_1step_beforeTarget(Head,list1);
	
	TEST_ASSERT_EQUAL(list0,Target);

	DestroyAllList(&Head,&Tail);
}

void test_travel_1step_beforeTarget_given_not_found_should_return_NULL()
{
	LinkedList *list0 = listCreate(0x100);
	LinkedList *list1 = listCreate(0x200);
	LinkedList *list2 = listCreate(0x300);
	LinkedList *list3 = listCreate(0x400);
	LinkedList *Head,*Tail, *Target ;
	
	listAddHead(&Head,list0);
	setTail(&Tail,Head);
	listAddTail(&Tail,list1);
	listAddTail(&Tail,list2);
	
	Target = travel_1step_beforeTarget(Head,list3);
	TEST_ASSERT_NULL(Target);
	
	DestroyAllList(&Head,&Tail);
}

void test_searchListForData_given_0x300_should_return_list2()
{
	LinkedList *list0 = listCreate(0x100);
	LinkedList *list1 = listCreate(0x200);
	LinkedList *list2 = listCreate(0x300);
	LinkedList *Head,*Tail, *Found ;
	
	listAddHead(&Head,list0);
	setTail(&Tail,Head);
	listAddTail(&Tail,list1);
	listAddTail(&Tail,list2);
	
	Found = searchListForData(Head,0x300);
	
	TEST_ASSERT_EQUAL(list2,Found);
	TEST_ASSERT_EQUAL(0x300,Found->data);
	
	DestroyAllList(&Head,&Tail);
	
}
	
void test_searchListForData_given_0x400_should_return_NULL_for_not_found()
{
	LinkedList *list0 = listCreate(0x100);
	LinkedList *list1 = listCreate(0x200);
	LinkedList *list2 = listCreate(0x300);
	LinkedList *Head,*Tail, *Found ;
	
	listAddHead(&Head,list0);
	setTail(&Tail,Head);
	listAddTail(&Tail,list1);
	listAddTail(&Tail,list2);
	
	Found = searchListForData(Head,0x400);
	
	TEST_ASSERT_NULL(Found);

	DestroyAllList(&Head,&Tail);
	
}