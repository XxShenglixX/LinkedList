#ifndef LinkedList_H
#define LinkedList_H

typedef struct LinkedList LinkedList;

#include <stdint.h>
#include <malloc.h>

struct LinkedList 
{
	uint32_t data;
	LinkedList *next;
};

#include "List_Utilities.h"

LinkedList *listCreate(uint32_t data);
void listDestroy(LinkedList *listToDestroy);
void DestroyAllList(LinkedList **Head,LinkedList **Tail);

void listAddHead(LinkedList **Head,LinkedList *listToAdd);
void listAddTail(LinkedList **Tail,LinkedList *listToAdd);
void listRemoveHead(LinkedList **Head,LinkedList **Tail);
void listRemoveTail(LinkedList **Head,LinkedList **Tail);



#endif // LinkedList_H
