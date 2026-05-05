#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1) return NULL;

    struct Node* root = newNode(arr[i]);
    root->left = buildTree(arr, n, 2*i+1);
    root->right = buildTree(arr, n, 2*i+2);

    return root;
}

struct Pair {
    struct Node* node;
    int hd;
};

void verticalOrder(struct Node* root) {
    if (!root) return;

    struct Pair q[1000];
    int front = 0, rear = 0;

    int map[2000][100];
    int count[2000] = {0};

    q[rear++] = (struct Pair){root, 1000};

    while (front < rear) {
        struct Pair p = q[front++];
        struct Node* node = p.node;
        int hd = p.hd;

        map[hd][count[hd]++] = node->data;

        if (node->left)
            q[rear++] = (struct Pair){node->left, hd-1};

        if (node->right)
            q[rear++] = (struct Pair){node->right, hd+1};
    }

    for (int i = 0; i < 2000; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++)
                printf("%d ", map[i][j]);
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    verticalOrder(root);

    return 0;
}