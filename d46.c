#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->left = n->right = NULL;
    return n;
}

int main() {
    int n, a[100];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    struct Node* nodes[100];

    for (int i = 0; i < n; i++) {
        if (a[i] == -1) nodes[i] = NULL;
        else nodes[i] = newNode(a[i]);
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int l = 2*i + 1;
            int r = 2*i + 2;
            if (l < n) nodes[i]->left = nodes[l];
            if (r < n) nodes[i]->right = nodes[r];
        }
    }

    struct Node* q[100];
    int front = 0, rear = 0;

    if (nodes[0] != NULL)
        q[rear++] = nodes[0];

    while (front < rear) {
        struct Node* temp = q[front++];
        printf("%d ", temp->data);

        if (temp->left != NULL)
            q[rear++] = temp->left;

        if (temp->right != NULL)
            q[rear++] = temp->right;
    }

    return 0;
}