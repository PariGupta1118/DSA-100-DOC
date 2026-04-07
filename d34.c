#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    top = n;
}

int pop() {
    int x = top->data;
    struct Node* t = top;
    top = top->next;
    free(t);
    return x;
}

int main() {
    char exp[100];
    printf("Enter postfix: ");
    fgets(exp, 100, stdin);

    int i = 0;
    while (exp[i] != '\0') {

        if (exp[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            int b = pop();
            int a = pop();

            if (exp[i] == '+') push(a + b);
            else if (exp[i] == '-') push(a - b);
            else if (exp[i] == '*') push(a * b);
            else if (exp[i] == '/') push(a / b);
        }
        i++;
    }

    printf("Result = %d\n", pop());
    return 0;
}