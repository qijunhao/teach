#pragma once

#include "myMath.h"

#define MAX_QUEUE_SIZE 20

typedef struct Queue
{
    u8 rear, head, size;
    float *data;
} Queue;

Queue *InitQueue(u8 size);

bool IfQueueEmpty(const Queue *queue);
bool IfQueueFull(const Queue *queue);

bool EnQueue(Queue *queue, float data);
bool DeQueue(Queue *queue, float *data);
