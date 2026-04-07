#include <stdio.h>

#define SIZE 100

int heap[SIZE];
int n = 0;

void insert(int x) {
    int i = n;
    heap[n++] = x;

    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[(i - 1) / 2];
        heap[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

int extractMin() {
    if (n == 0) return -1;

    int min = heap[0];
    heap[0] = heap[n - 1];
    n--;

    int i = 0;
    while (2 * i + 1 < n) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int small = left;

        if (right < n && heap[right] < heap[left])
            small = right;

        if (heap[i] <= heap[small]) break;

        int temp = heap[i];
        heap[i] = heap[small];
        heap[small] = temp;

        i = small;
    }

    return min;
}

int peek() {
    if (n == 0) return -1;
    return heap[0];
}

int main() {
    int N, x;
    char op[20];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (op[0] == 'i') {
            scanf("%d", &x);
            insert(x);
        } 
        else if (op[0] == 'e') {
            printf("%d\n", extractMin());
        } 
        else if (op[0] == 'p') {
            printf("%d\n", peek());
        }
    }

    return 0;
}