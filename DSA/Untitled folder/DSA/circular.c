#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int f = -1, r = -1;

void enqueue(int value) {
    if ((r + 1) % SIZE == f) {
        printf("Queue Overflow\n");
        return;
    }
    if (f == -1 && r == -1) {
        f = r = 0;
        queue[r] = value;
    } else {
        r = (r + 1) % SIZE;
        queue[r] = value;
    }
    printf("Inserted Successfully\n");
}

void dequeue() {
    if (f == -1 && r == -1) {
        printf("Queue Underflow\n");
        return;
    }
    if (f == r) {
        
        f = r = -1;
    } else {
        f = (f + 1) % SIZE;
    }
    printf("Deleted Successfully\n");
}

void search(int value) {
    if (f == -1 && r == -1) {
        printf("Queue is empty\n");
        return;
    }
    int found = 0;
    int temp = f;
    while (1) {
        if (queue[temp] == value) {
            printf("Value %d found at position %d\n", value, temp);
            found = 1;
            
        }
        if (temp == r)
            break;
        temp = (temp + 1) % SIZE;
    }
    if (!found) {
        printf("Value %d not found in queue\n", value);
    }
}

void display() {
    if (f == -1 && r == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int temp = f;
    while (1) {
        printf("%d ,", queue[temp]);
        if (temp == r)
            break;
        temp = (temp + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, value;
    do {
        printf("\n---Menu Operations---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Enter the value to be searched: ");
                scanf("%d", &value);
                search(value);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid Entry\n");
                break;
        }
    } while (1);

    return 0;
}
