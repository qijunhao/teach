#include "inc/list.h"

// 双向链表
List *InitList()
{
    List *list = (List *)malloc(sizeof(List));
    if (!list)
        return NULL;

    list->head = (ListNode *)malloc(sizeof(ListNode));
    list->tail = (ListNode *)malloc(sizeof(ListNode));

    if ((!list->head) || (!list->tail))
    {
        free(list);
        free(list->head);
        free(list->tail);
        return NULL;
    }

    list->head->next = list->head->prev = list->tail;
    list->tail->next = list->tail->prev = list->head;
    list->dataCount = 0;
    return list;
};

bool ListHeadInsert(List *list, float data)
{
    ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
    if (!newnode)
        return false;

    newnode->data = data;

    newnode->prev = list->head;
    newnode->next = list->head->next;

    list->head->next->prev = newnode;
    list->head->next = newnode;

    list->dataCount++;
    return true;
};

bool ListTailInsert(List *list, float data)
{
    ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
    if (!newnode)
        return false;

    newnode->data = data;

    newnode->prev = list->tail->prev;
    newnode->next = list->tail;

    list->tail->prev->next = newnode;
    list->tail->prev = newnode;

    list->dataCount++;
    return true;
};

bool ListHeadDelete(List *list, float *data)
{
    if (!list->dataCount)
        return false;

    ListNode *deleteNode = list->head->next;
    *data = deleteNode->data;

    list->head->next = deleteNode->next;
    deleteNode->next->prev = list->head;

    free(deleteNode);
    list->dataCount--;
    return true;
};

bool ListTailDelete(List *list, float *data)
{
    if (!list->dataCount)
        return false;

    ListNode *deleteNode = list->tail->prev;
    *data = deleteNode->data;

    list->tail->prev = deleteNode->prev;
    deleteNode->prev->next = list->tail;

    free(deleteNode);
    list->dataCount--;
    return true;
};

bool FindInList(const List *list, float data)
{
    ListNode *indexNode = list->head->next;
    while (indexNode != list->tail)
    {
        if (indexNode->data == data)
            return true;
        indexNode = indexNode->next;
    }
    return false;
};

void TravelList(const List *list, void (*func)(float), const ListTravelMode travel_mode)
{
    if (travel_mode == ListFront2Tail)
    {
        ListNode *indexNdoe = list->head->next;
        while (indexNdoe != list->tail)
        {
            func(indexNdoe->data);
            indexNdoe = indexNdoe->next;
        }
    }
    else if (travel_mode == ListTail2Front)
    {
        ListNode *indexNdoe = list->tail->prev;
        while (indexNdoe != list->head)
        {
            func(indexNdoe->data);
            indexNdoe = indexNdoe->prev;
        }
    }
};

bool ListPrevInsert(ListNode *listnode, float data)
{
    ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
    if (!newnode)
        return false;

    newnode->data = data;

    newnode->prev = listnode->prev;
    newnode->next = listnode;

    listnode->prev->next = newnode;
    listnode->prev = newnode;
    // newnode->next->prev = newnode;
    // newnode->prev->next = newnode;
    return true;
}

bool ListNextInsert(ListNode *listnode, float data)
{
    ListNode *newnode = (ListNode *)malloc(sizeof(ListNode));
    if (!newnode)
        return false;

    newnode->data = data;

    newnode->next = listnode->next;
    newnode->prev = listnode;

    newnode->next->prev = newnode;
    newnode->prev->next = newnode;
    return true;
};
bool ListPrevDelete(ListNode *listnode, float *data)
{
    if (!listnode->prev)
        return false;

    ListNode *deleteNode = listnode->prev;
    *data = deleteNode->data;

    listnode->prev = deleteNode->prev;
    listnode->next = deleteNode->next;
    deleteNode->prev->next = listnode;
    deleteNode->next->prev = listnode;
};
bool ListPrevDelete(ListNode *listnode, float *data);
