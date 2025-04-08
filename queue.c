#include <stdio.h>

int queue[10];
int front,rear;
int n;

void init(int queue[]) {
    front = -1, rear = -1;
}

//empty
//Description: checking queue is empty
//Input: none
//Output: 1(empty) or 0(no empty) 
int empty() {
    return front == -1;
}

//full
//Description: checking queue is full
//Input: none
//Output: 1(full) or 0(no full)
int full() {
    return rear == 10;
}

//enqueue
//Description: enqueue integer into stack
//Input: integer
//Output: none
void enqueue(int value) {
    if (full()) {
        return;
    }
    if (empty()) {
        front++;
    }
    queue[++rear] = value;
}

//dequeue
//Description: dequeue integer to stack
//Input: none
//Output: dequeued integer
int dequeue() {
    if (empty()) {
        return;
    }
    int temp = queue[front];
    front++;
    return temp;
}

void printqueue() {
    printf("\ncurrent queue:");
    for (int i = front; i <= rear; i++) {
        if (rear == 10) {
            break;
        }
        printf("%d ", queue[i]);
        
    }
    printf("\n");
}
void main() {
    init(queue);
    while (1) {
        printf("type enqueue integer (dequeue is -1):");
        scanf("%d", &n);
        if (n == -1) {
            n = dequeue();
            
            if (front == -1) {
                printf("queue is already empty\n");
                break;
            }
            printf("dequeued integer : %d\n", n);
        }
        else {
            enqueue(n);
        }
        if (full()) {
            printf("queue is already full\n");
            break;
        }
        printqueue();
        if (empty()) {
            printf("queue is already empty\n");
            break;
        }
        
    }

}
