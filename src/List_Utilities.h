#ifndef List_Utilities_H
#define List_Utilities_H

#include <stdint.h>
#include "LinkedList.h"

int checkIsListNull(LinkedList *listPtr);
int checkIsListMatchTarget(LinkedList *listPtr,LinkedList *target);
int checkIsHeadEQTail(LinkedList *Head,LinkedList *Tail);

LinkedList *travel_1step_beforeTarget(LinkedList *Head,LinkedList *target);
LinkedList *searchListForData(LinkedList *Head,uint32_t data);

void setHead(LinkedList **Head,LinkedList *listHead);
void setTail(LinkedList **Tail,LinkedList *listTail);
#endif // List_Utilities_H
