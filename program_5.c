#include <stdio.h>
#define MAX 5

typedef struct {
    int a[MAX], front, rear;
} Queue;

void enqueue(Queue *q, int x) {
    if ((q->rear + 1) % MAX == q->front)
        printf("Queue Full\n");
    else {
        if (q->front == -1) q->front = 0;
        q->rear = (q->rear + 1) % MAX;
        q->a[q->rear] = x;
    }
}

void dequeue(Queue *q) {
    if (q->front == -1)
        printf("Queue Empty\n");
    else {
        printf("Deleted: %d\n", q->a[q->front]);
        if (q->front == q->rear)
            q->front = q->rear = -1;
        else q->front = (q->front + 1) % MAX;
    }
}

void display(Queue *q) {
    if (q->front == -1) return;
    int i = q->front;
    while (1) {
        printf("%d ", q->a[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Queue q = {.front = -1, .rear = -1};
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);
    dequeue(&q);
    display(&q);
    return 0;
}

