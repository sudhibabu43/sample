#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;


void insert_beginning(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("Inserted %d at beginning\n", value);
}

void insert_end(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %d at end\n", value);
}


void insert_pos(int pos, int value) {
    if (pos < 0) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 0) {
        insert_beginning(value);
        return;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node *temp = head;
    int count = 0;

  
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("Inserted %d at position %d\n", value, pos);
}


void display() {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void delete_beginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }
    printf("Deleted %d from beginning\n", temp->data);
    free(temp);
}

void delete_end() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;

    if (temp->next == NULL) {
       
        printf("Deleted %d from end\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }

 
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    printf("Deleted %d from end\n", temp->data);
    free(temp);
}


void delete_pos(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos < 0) {
        printf("Invalid position\n");
        return;
    }
    struct Node *temp = head;
    int count = 0;

    if (pos == 0) {
        delete_beginning();
        return;
    }

    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    printf("Deleted %d from position %d\n", temp->data, pos);
    free(temp);
}

void search(int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    int pos = 0;
    int found = 0;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d\n", value, pos);
            found = 1;
            break; 
        }
        temp = temp->next;
        pos++;
    }
    if (!found) {
        printf("Value %d not found in the list\n", value);
    }
}

int main() {
    int choice, value, pos;
    printf("\n\t----MENU----\n\n");
    while (1) {
        printf("\n 1. Insert at beginning\n 2. Insert at position\n 3. Insert at end\n 4. Display\n");
        printf(" 5. Delete at beginning\n 6. Delete at position\n 7. Delete at end\n 8. Search\n 9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                insert_beginning(value);
                break;
            case 2:
                printf("Enter the position (0-based): ");
                scanf("%d", &pos);
                printf("Enter the value: ");
                scanf("%d", &value);
                insert_pos(pos, value);
                break;
            case 3:
                printf("Enter the value: ");
                scanf("%d", &value);
                insert_end(value);
                break;
            case 4:
                display();
                break;
            case 5:
                delete_beginning();
                break;
            case 6:
                printf("Enter the position (0-based): ");
                scanf("%d", &pos);
                delete_pos(pos);
                break;
            case 7:
                delete_end();
                break;
            case 8:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Wrong choice!!\n");
                break;
        }
    }
    return 0;
}
