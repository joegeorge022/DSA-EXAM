#include <stdio.h>

int queue[100];
int MAX, front = -1, rear = -1;

void enqueue(int value) {
    if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
        queue[rear] = value;
    } else {
        rear = (rear + 1) % MAX;
        queue[rear] = value;
    }
    printf("%d enqueued\n", value);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("%d dequeued\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    printf("Queue: ");
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;

    printf("Enter the size of the circular queue (Max up to 100): ");
    scanf("%d", &MAX);
    if (MAX <= 0 || MAX > 100) {
        printf("Invalid size!\n");
        return 1;
    }

    while (1) {
        printf("\n1. Enqueue\t2. Dequeue\t3. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &value);
                enqueue(value);
                display();
                break;
            case 2:
                dequeue();
                display();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
