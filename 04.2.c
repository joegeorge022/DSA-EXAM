#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

//SAME AS ENQUEUE IN NORMAL QUEUE
void insertRear(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = x;
    printf("%d inserted at rear.\n", x);
}

//SAME AS DEQUEUE IN NORMAL QUEUE
void deleteFront() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("%d removed from front.\n", queue[front++]);
    if (front > rear) front = rear = -1;
}

void insertFront(int x) {
    if (front == 0) {
        printf("No space at front!\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        front--;
    }
    queue[front] = x;
    printf("%d inserted at front.\n", x);
}


void deleteRear() {
    if (rear == -1) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("%d removed from rear.\n", queue[rear--]);
    if (rear < front) front = rear = -1;
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Deque elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\nDouble Ended Queue Using Array");
        printf("\n1. Insert Front");
        printf("\n2. Insert Rear");
        printf("\n3. Delete Front");
        printf("\n4. Delete Rear");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                insertFront(val);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertRear(val);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
