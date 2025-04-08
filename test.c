#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node node[10];
int front = -1;
int rear = -1;
int count = 0;

void init() {
    for (int i = 0; i < 10; i++) {
        node[i].data = 0;
        node[i].next = (i == 9) ? NULL : &node[i + 1];
    }
}

int empty() {
    return count == 0;
}

int full() {
    return count == 10;
}

void enqueue(int value) {
    if (full()) {
        printf("Queue is already full\n");
        return;
    }
    if (empty()) {
        front = 0;
    }
    node[++rear].data = value;
    count++;
}

int dequeue() {
    if (empty()) {
        return -1;
    }
    int temp = node[front++].data;
    count--;
    return temp;
}

void printq() {
    if (empty()) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", node[i].data);
    }
    printf("\n");
}

int main() {
    int n;
    init();  // ✅ 반드시 초기화 호출

    int iteration = 0;  // 최대 실행 횟수 설정
    while (iteration < 20) {  // 20번 반복 후 자동 종료
        printf("Type enqueue integer (dequeue is -1): ");
        if (scanf("%d", &n) != 1) {  // 🚨 입력 오류 방지
            printf("Invalid input! Exiting...\n");
            break;
        }

        if (n == -1) {
            n = dequeue();
            if (n == -1) {
                printf("Queue is already empty\n");
                break;
            }
            printf("Dequeued integer: %d\n", n);
        } else {
            enqueue(n);
        }

        if (full()) {
            printf("Queue is already full\n");
            break;
        }

        printq();

        if (empty()) {
            printf("Queue is already empty\n");
            break;
        }

        iteration++;  // 실행 횟수 증가
    }

    return 0;
}
