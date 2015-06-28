#include "LinkedList.h"

LinkedList *listCreate(uint32_t data)
{
	LinkedList *list = malloc(sizeof(LinkedList));
	
	list->data = data ;
	list->next = NULL ;
	
	return list ;
}

void listDestroy(LinkedList *listToDestroy)
{
	listToDestroy->next = NULL ;
	free(listToDestroy);
}

void DestroyAllList(LinkedList **Head,LinkedList **Tail)
{
	LinkedList *destroyList ;
	LinkedList *nextList = (*Head)->next ;
	
	while(!checkIsListNull(nextList))
	{
		destroyList = *Head ;
		*Head = nextList ; //Head move to the next list
		nextList = (*Head)->next ; //Store the next list after Head
		listDestroy(destroyList);
	}
	
	setHead(Head,NULL);
	setTail(Tail,NULL);
}

void listAddHead(LinkedList **Head,LinkedList *listToAdd)
{
	LinkedList *temp ;
	
	if(checkIsListNull(*Head))
		setHead(Head,listToAdd);
	else
	{
		temp = *Head ;
		*Head = listToAdd ;
		listToAdd->next = temp;
	}
}

void listAddTail(LinkedList **Tail,LinkedList *listToAdd)
{
	LinkedList *current = *Tail ;
	
	current->next = listToAdd ;
	setTail(Tail,listToAdd);
}

void listRemoveHead(LinkedList **Head,LinkedList **Tail)
{
	LinkedList *destroyList = *Head ;
 	LinkedList *nextList ;
	
	if(checkIsListNull(*Head))
		setHead(Head,NULL);
	else
	{
		nextList = (*Head)->next;
		
		if(checkIsListNull(nextList)) //only 1 element in the List
		{
			setHead(Head,NULL);
			setTail(Tail,NULL);
		}
		else	
			*Head = nextList ;
		
		listDestroy(destroyList);
	}
}

void listRemoveTail(LinkedList **Head,LinkedList **Tail)
{
	LinkedList *destroyList = *Tail ;
	LinkedList *previousList ;
	
	if(checkIsHeadEQTail(*Head,*Tail)) //Head = Tail , 1 element only in List
	{
		setHead(Head,NULL);
		setTail(Tail,NULL);
		listDestroy(destroyList);
	}
	else
	{
		previousList = travel_1step_beforeTarget((*Head),(*Tail)); //acquire list 1 step before tail
		setTail(Tail,previousList); //set tail to previousList
		previousList->next = NULL ;
		listDestroy(destroyList);
	}
	
}

