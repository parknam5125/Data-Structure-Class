#include <stdio.h>

int stack[10];
int top;
int n;
 
void init(int stack[]) {
    top = -1;
}

//empty
//Description: checking stack is empty
//Input: none
//Output: 1(empty) or 0(no empty)
int empty() {
    return top == -1;
}

//full
//Description: checking stack is full
//Input: none
//Output: 1(full) or 0(no full)
int full() {
    return top == 10;
}

//push
//Description: push integer into stack
//Input: integer
//Output: none
void push(int value) {
    if (full()) {
        return;                     
    }                                     
    stack[++top] = value;
}

//pop
//Description: pop integer to stack
//Input: none
//Output: poped integer
int pop() {
    if (empty()) {
        return;
    }
    int temp = stack[top];
    top--;
    return temp;
}

void printstack() {
    printf("\ncurrent stack: \n");
    for (int i = 0; i <= top; i++) {
        if (top == 10) {
            break;
        }
        printf("%d ", stack[i]);

    }
    printf("\n");
}

void main() {
    init(stack);
    while (1) {
        printf("type push integer (-1 is pop):\n");
        scanf_s("%d", &n);
        if (n == -1) {
            n = pop();
            if (top == -1) {
                printf("stack is already empty\n");
                break;
            }
            printf("poped integer : %d\n",n);
        }
        else {
            push(n);
        }
        if (full()) {
            printf("stack is full\n");
            break;
        }
        printstack();
        if (empty()) {
            printf("stack is empty\n");
            break;
        }
        
    }
    
}