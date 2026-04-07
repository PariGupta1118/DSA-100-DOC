#include <stdio.h>

int main() {
    int n, q[100], stack[100], top = -1;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    for (int i = 0; i < n; i++)
        stack[++top] = q[i];

    for (int i = 0; i < n; i++)
        q[i] = stack[top--];

    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);

    return 0;
}