
#include <stdio.h>
#define MAX 5

typedef struct {
    int a[MAX], front, rear;
} Queue;

void enqueue(Queue *q, int x) {
    if (q->rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        if (q->front == -1) q->front = 0;
        q->a[++q->rear] = x;
    }
}

void dequeue(Queue *q) {
    if (q->front == -1 || q->front > q->rear)
        printf("Queue Underflow\n");
    else
        printf("Deleted: %d\n", q->a[q->front++]);
}

void display(Queue *q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->a[i]);
    printf("\n");
}

int main() {
    Queue q = {.front = -1, .rear = -1};

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    display(&q);
    dequeue(&q);
    display(&q);

    return 0;
}
