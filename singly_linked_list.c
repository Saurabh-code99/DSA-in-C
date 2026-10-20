#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;
void insert(int x, int pos) {
    Node *n = malloc(sizeof(Node));
    n->data = x;

    if (pos == 1) {
        n->next = head;
        head = n;
        return;
    }

    Node *p = head;
    for (int i = 1; p && i < pos-1; i++)
        p = p->next;

    if (!p) {
        free(n);
        printf("Invalid position\n");
        return;
    }

    n->next = p->next;
    p->next = n;
}

void delete(int pos) {
    if (!head) {
        printf("List is empty\n");
        return;
    }

    Node *p = head;

    if (pos == 1) head = head->next;
    else {
        for (int i = 1; p && i < pos-1; i++)
            p = p->next;

        if (!p || !p->next) {
            printf("Invalid position\n");
            return;
        }

        Node *t = p->next;
        p->next = t->next;
        free(t);
        return;
    }
    free(p);
}

void display() {
    Node *p = head;
    while (p) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    insert(10, 1);
    insert(20, 2);
    insert(30, 3);
    insert(40, 4);
    printf("Initial list: ");
    display();

    insert(5, 1);
    printf("After insertion at beginning: ");
    display();

    insert(50, 7);
    printf("After insertion at end: ");
    display();

    insert(25, 4);
    printf("After insertion at 4th position: ");
    display();

    delete(1);
    printf("After deletion at beginning: ");
    display();

    delete(6);
    printf("After deletion at end: ");
    display();
    return 0;
}

