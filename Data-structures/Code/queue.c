#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Queue {
    int front;
    int rear;
    int capacity;
    int size;
    int * arr;
};

struct Queue* createQueue (int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = capacity;
    queue->arr = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
};


bool IsFull (struct Queue* queue) {
    return (queue->rear+1)%queue->capacity == queue->front;
}

bool IsEmpty(struct Queue *queue) {
    return queue->rear == queue->front;
}

void Enqueue (struct Queue* queue, int item) {
    if (!IsFull(queue)) {
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->arr[queue->rear] = item;
        queue->size++;
        printf("front = %d, rear = %d\n", queue->front, queue->rear);
    }
    else {
        printf("Queue is full\n");
        return;
    }
}

void Dequeue (struct Queue* queue) {
    if (!IsEmpty(queue)) {
        queue->front = (queue->front + 1) % queue->capacity;    // circular queue
        queue->size--;
        printf("Removing  %d\n", queue->front);
    }

    else {
        printf("Queue is empty\n");
        return;
    }
}

int main() {
    struct Queue *queue = createQueue(5);
 
    Enqueue(queue, 1);
    Enqueue(queue, 2);
    Enqueue(queue, 3);
    Enqueue(queue, 4);
 
    Dequeue(queue);
    Dequeue(queue);
    Dequeue(queue);
    Dequeue(queue);
 
    Enqueue(queue, 5);
    Enqueue(queue, 6);
 
    printf("size = %d\n", queue->size);
 
    if (IsEmpty(queue))
        printf("Queue is empty");
    else
        printf("Queue is not empty");
 
    return 0;
}