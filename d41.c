#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;

    if (rear == NULL) {
        front = rear = n;
    } else {
        rear->next = n;
        rear = n;
    }
}

int dequeue() {
    if (front == NULL) return -1;

    int x = front->data;
    struct Node* t = front;
    front = front->next;

    if (front == NULL) rear = NULL;

    free(t);
    return x;
}

int main() {
    int N, x;
    char op[10];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (op[0] == 'e') {
            scanf("%d", &x);
            enqueue(x);
        } else if (op[0] == 'd') {
            printf("%d\n", dequeue());
        }
    }

    return 0;
}