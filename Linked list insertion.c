//Linked list insertion
//https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/1



#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int x) {
    struct Node* newNode = createNode(x);
    if (head == NULL) {
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) 
            printf("->");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, value, x, i;
    struct Node* head = NULL;
    struct Node* tail = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n > 0) {
        printf("Enter %d node values: ", n);
        for (i = 0; i < n; i++) {
            scanf("%d", &value);
            struct Node* newNode = createNode(value);
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    printf("Enter value to insert at end: ");
    scanf("%d", &x);

    head = insertAtEnd(head, x);

    printf("Modified Linked List: ");
    printList(head);

    return 0;
}

