#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) { 
    if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = value;
    } else if ((rear + 1) % MAX == front) {
        printf("Overflow!\n");
        return;
    } else {
        rear = (rear + 1) % MAX;
        queue[rear] = value;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Underflow!\n");
        return;
    } else if (front == rear) {
        printf("Dequeued: %d\n", queue[front]);
        front = rear = -1;
    } else {
        printf("Dequeued: %d\n", queue[front]);
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is EMPTY!\n");
        return;
    }

    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}