#include "List_Utilities.h"

int checkIsListNull(LinkedList *listPtr)
{
	if (listPtr == NULL)
		return 1 ;
	else
		return 0 ;
}

int checkIsListMatchTarget(LinkedList *listPtr,LinkedList *target)
{
	if (listPtr == target)
		return 1 ;
	else 
		return 0;
}

int checkIsHeadEQTail(LinkedList *Head,LinkedList *Tail)
{
	checkIsListMatchTarget(Head,Tail);
}


void setHead(LinkedList **Head,LinkedList *listHead)
{
	*Head = listHead ;
}
void setTail(LinkedList **Tail,LinkedList *listTail)
{
	*Tail = listTail ;
}

LinkedList *travel_1step_beforeTarget(LinkedList *Head,LinkedList *target)
{
	LinkedList *current = Head;
	LinkedList *nextList = current->next ;
	
	while (! checkIsListNull(nextList)) //next is not NULL
	{
		if (checkIsListMatchTarget(nextList,target))//if match
			return current ;
		else
		{
			current = nextList ; //travel to the next
			nextList = current->next ;
		}
	}
	return NULL ;//not found
}


LinkedList *searchListForData(LinkedList *Head,uint32_t data)
{
	LinkedList *current = Head;
	LinkedList *nextList ;
	
	while (! checkIsListNull(current)) 
	{
		if (current->data == data)
			return current ;
		else //not match
		{
			nextList = current->next ;
			if(!checkIsListNull(nextList)) //check if nextList is not NULL
				current =nextList ;
			else //nextList is empty and not match data found
				current = NULL ;
		}
	}
	return NULL ;//not found
}