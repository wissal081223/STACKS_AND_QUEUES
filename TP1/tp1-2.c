#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int customerNumber;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue q) {
    return (q.front == NULL);
}

void enqueue(Queue* q, int number) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->customerNumber = number;
    newNode->next = NULL;

    if (isEmpty(*q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (isEmpty(*q)) {
        return -1;
    }
    Node* temp = q->front;
    int number = temp->customerNumber;

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return number;
}

int peek(Queue q) {
    if (isEmpty(q)) {
        return -1;
    }
    return q.front->customerNumber;
}

int main() {
    Queue bankQueue;
    initQueue(&bankQueue);

    printf("=== Part 2: Bank Queue Simulation ===\n\n");

    printf("Customer 101 arrived and got a token.\n");
    enqueue(&bankQueue, 101);

    printf("Customer 102 arrived and got a token.\n");
    enqueue(&bankQueue, 102);

    if (!isEmpty(bankQueue)) {
        printf("Customer %d is being served.\n", dequeue(&bankQueue));
    }

    printf("Customer 103 arrived and got a token.\n");
    enqueue(&bankQueue, 103);

    if (!isEmpty(bankQueue)) {
        printf("Customer %d is being served.\n", dequeue(&bankQueue));
    }

    if (!isEmpty(bankQueue)) {
        printf("Customer %d is being served.\n", dequeue(&bankQueue));
    }

    if (isEmpty(bankQueue)) {
        printf("Queue is empty.\n");
    }

    return 0;
}
