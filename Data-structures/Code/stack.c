#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    int capacity;
    int* array;
};

struct Stack* createStack (int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
};

bool isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
};

bool isEmpty (struct Stack* stack) {
    return stack->top == -1;
};

void push (struct Stack* stack, int item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
};

void pop(struct Stack* stack) {
    stack->array[stack->top--];
        if (isEmpty(stack)) return;
}

int size(struct Stack* stack) {
    return stack->top+1;
}

void listStack(struct Stack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");

}



int main() {
    int N;
    char op[10];

    scanf("%d", &N);
    struct Stack* s = createStack(N);

    do {
        scanf("%s", op);

        if (!strcmp(op, "push")) {
            int input;
            scanf("%d", &input);
            push(s, input);
            listStack(s);
        }

        else if (!strcmp(op, "pop")) {
            pop(s);
            listStack(s);
        }

        else if (!strcmp(op, "size")) {
            printf("stack's size is %d\n", size(s));
        }

        else if (!strcmp(op, "list")) {
            listStack(s);
        }

        else {
            printf("type push or pop or size\n");
        }
    } while (strcmp(op, "q"));

    return 0;

}