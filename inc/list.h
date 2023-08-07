#pragma once

#include "myMath.h"

typedef enum ListTravelMode
{
    ListFront2Tail,
    ListTail2Front
} ListTravelMode;

typedef struct ListNode
{
    struct ListNode *prev;
    struct ListNode *next;
    float data;
} ListNode;

typedef struct List
{
    ListNode *head, *tail;
    int dataCount;
} List;

List *InitList(void);

bool ListPrevInsert(ListNode *listndoe, float data);
bool ListNextInsert(ListNode *listndoe, float data);
bool ListPrevDelete(ListNode *listndoe, float *data);
bool ListPrevDelete(ListNode *listndoe, float *data);

bool ListHeadInsert(List *list, float data);
bool ListTailInsert(List *list, float data);

bool ListHeadDelete(List *list, float *data);
bool ListTailDelete(List *list, float *data);

bool FindInList(const List *list, float data);

void TravelList(const List *list, void (*func)(float), const ListTravelMode travel_mode);