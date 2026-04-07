#include <stdio.h>

#define SIZE 100

int pq[SIZE];
int n = 0;

void insert(int x) {
    int i = n - 1;
    while (i >= 0 && pq[i] > x) {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1] = x;
    n++;
}

int delete() {
    if (n == 0) return -1;
    return pq[--n];
}

int peek() {
    if (n == 0) return -1;
    return pq[0];
}

int main() {
    int N, x;
    char op[10];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (op[0] == 'i') {
            scanf("%d", &x);
            insert(x);
        } 
        else if (op[0] == 'd') {
            printf("%d\n", delete());
        } 
        else if (op[0] == 'p') {
            printf("%d\n", peek());
        }
    }

    return 0;
}