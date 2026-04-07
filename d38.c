#include <stdio.h>

#define SIZE 100

int dq[SIZE];
int front = -1, rear = -1;

void push_front(int x) {
    if (front == -1) front = rear = 0;
    else front--;
    dq[front] = x;
}

void push_back(int x) {
    if (rear == -1) front = rear = 0;
    else rear++;
    dq[rear] = x;
}

void pop_front() {
    if (front == -1) return;
    if (front == rear) front = rear = -1;
    else front++;
}

void pop_back() {
    if (rear == -1) return;
    if (front == rear) front = rear = -1;
    else rear--;
}

int get_front() {
    if (front == -1) return -1;
    return dq[front];
}

int get_back() {
    if (rear == -1) return -1;
    return dq[rear];
}

int size() {
    if (front == -1) return 0;
    return rear - front + 1;
}

int main() {
    int n, x;
    char op[20];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0]=='p' && op[5]=='f') {
            scanf("%d", &x);
            push_front(x);
        }
        else if (op[0]=='p' && op[5]=='b') {
            scanf("%d", &x);
            push_back(x);
        }
        else if (op[0]=='p' && op[4]=='f') pop_front();
        else if (op[0]=='p' && op[4]=='b') pop_back();
        else if (op[0]=='f') printf("%d\n", get_front());
        else if (op[0]=='b') printf("%d\n", get_back());
        else if (op[0]=='s') printf("%d\n", size());
    }

    return 0;
}