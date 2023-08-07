#include "inc/queue.h"

Queue *InitQueue(u8 size)
{
    if (size < 1)
        return NULL;
    if (size > MAX_QUEUE_SIZE)
        size = MAX_QUEUE_SIZE;

    Queue *queue = (Queue *)malloc((sizeof(Queue)));
    if (!queue)
        return NULL;

    queue->head = queue->rear = 0;
    queue->size = size;
    queue->data = (float *)malloc(sizeof(float) * size);

    return queue;
};

bool IfQueueEmpty(const Queue *queue) { return queue->head == queue->rear; };
bool IfQueueFull(const Queue *queue) { return queue->head == (queue->rear + 1); };

bool EnQueue(Queue *queue, float data)
{
    if (IfQueueFull(queue))
        return false;

    queue->data[queue->rear++] = data;
    queue->rear %= queue->size;
    return true;
}
bool DeQueue(Queue *queue, float *data)
{
    if (IfQueueEmpty(queue))
        return false;

    *data = queue->data[queue->head++];
    queue->head %= queue->size;
    return true;
};
