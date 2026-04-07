#include <stdio.h>

#define SIZE 100

int q[SIZE];
int front = -1, rear = -1;

void enqueue(int x) {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    q[rear] = x;
}

void dequeue() {
    if (front == -1) return;

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) return;

    int i = front;
    while (1) {
        printf("%d ", q[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();
    return 0;
}