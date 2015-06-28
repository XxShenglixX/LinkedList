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

void test_listCreate_should_create_list_with_the_data()
{
	LinkedList *list = listCreate(0x200);
	
	TEST_ASSERT_NOT_NULL(list);
	TEST_ASSERT_EQUAL(0x200,list->data);
	TEST_ASSERT_NULL(list->next);
	
	listDestroy(list);
}



void test_listAddHead_should_make_list_to_head_if_head_is_null()
{
	LinkedList *list = listCreate(0x200) ;
	LinkedList *head = NULL;
	
	listAddHead(&head,list);
	TEST_ASSERT_EQUAL(head,list);
	TEST_ASSERT_EQUAL(0x200,head->data);
	TEST_ASSERT_NULL(list->next);
	
	listDestroy(list);
}

void test_listAddHead_should_make_list_to_head_and_link_nextList_if_head_is_not_null()
{
	
	LinkedList *list = listCreate(0x100) ;
	LinkedList *list2 = listCreate(0x200) ;
	LinkedList *head = list ;
	
	listAddHead(&head,list2);
	
	TEST_ASSERT_EQUAL(list2,head);
	TEST_ASSERT_EQUAL(0x200,head->data);
	TEST_ASSERT_EQUAL(list,head->next);
	TEST_ASSERT_EQUAL(0x100,(head->next)->data);
	
	listDestroy(list);
	listDestroy(list2);
}

void test_listAddTail_should_add_list_to_tail()
{
	LinkedList *list = listCreate(0x100) ;
	LinkedList *list2 = listCreate(0x200) ;
	LinkedList *tail = list ;
	
	listAddTail(&tail,list2);
	
	TEST_ASSERT_EQUAL(list2,tail);
	TEST_ASSERT_EQUAL(0x200,tail->data);
	TEST_ASSERT_EQUAL(list2,list->next);

	listDestroy(list);
	listDestroy(list2);
}

void test_listRemoveHead_should_set_Head_to_NULL_if_list_only_contain_1_element()
{
	LinkedList *list = listCreate(0x100) ;
	LinkedList *head = list ;
	LinkedList *tail = list ;
	
	listRemoveHead(&head,&tail);
	
	TEST_ASSERT_NULL(head);	
	TEST_ASSERT_NULL(tail);	
}

void test_listRemoveHead_should_set_Head_to_2nd_element_if_list_contain_multiple_element()
{
	LinkedList *list = listCreate(0x100);
	LinkedList *list2 = listCreate(0x200);
	LinkedList *head = NULL ;
	LinkedList *tail = NULL ;
	
	listAddHead(&head,list);
	tail = head ;
	listAddTail(&tail,list2);
	
	listRemoveHead(&head,&tail);
	
	TEST_ASSERT_EQUAL(list2,head);
	TEST_ASSERT_EQUAL(list2,tail);
	
	DestroyAllList(&head,&tail);
}

void test_listRemoveTail_given_3_element_list_should_become_2_element_list()
{
	LinkedList *list0 = listCreate(0x100);
	LinkedList *list1 = listCreate(0x200);
	LinkedList *list2 = listCreate(0x300);
	LinkedList *Head,*Tail ;
	
	listAddHead(&Head,list0);
	setTail(&Tail,Head);
	listAddTail(&Tail,list1);
	listAddTail(&Tail,list2);
	
	listRemoveTail(&Head,&Tail);
	
	TEST_ASSERT_EQUAL(list1,Tail);
	
	DestroyAllList(&Head,&Tail);
}

void test_listRemoveTail_given_1_element_list_should_set_Head_and_Tail_to_NULL()
{
	LinkedList *list0 = listCreate(0x100);
	LinkedList *Head,*Tail ;
	
	listAddHead(&Head,list0);
	setTail(&Tail,Head);
	
	listRemoveTail(&Head,&Tail);
	
	TEST_ASSERT_NULL(Head);
	TEST_ASSERT_NULL(Tail);
}