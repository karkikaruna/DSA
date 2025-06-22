#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct queue {
    int front;
    int rear;
    int data[MAX];
};

int isFull(struct queue *q) {
    return q->rear == MAX - 1;
}

int isEmpty(struct queue *q) {
    return q->front > q->rear;
}

void enqueue(struct queue *q, int element) {
    if (isFull(q)) {
        printf("Queue is full.\n");
    } else {
        q->rear += 1;
        q->data[q->rear] = element;
        printf("%d is ENQUEUED.\n", element);
    }
}

int dequeue(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        int element = q->data[q->front];
        q->front += 1;
        return element;
    }
}

void display(struct queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("The elements in the queue are: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    struct queue q;
    q.front = 0;
    q.rear = -1;

    int choice, element, result;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Check if Full\n");
        printf("4. Check if Empty\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);
                enqueue(&q, element);
                break;
            case 2:
                result = dequeue(&q);
                if (result != -1)
                    printf("%d is DEQUEUED.\n", result);
                break;
            case 3:
                if (isFull(&q))
                    printf("Queue is full.\n");
                else
                    printf("Queue is not full.\n");
                break;
            case 4:
                if (isEmpty(&q))
                    printf("Queue is empty.\n");
                else
                    printf("Queue is not empty.\n");
                break;
            case 5:
                display(&q);
                break;
            case 6:
                printf("Exiting....\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
