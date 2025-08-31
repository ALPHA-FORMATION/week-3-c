//Hackerrank: Print elements of linked list
//https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list/problem



#include <stdio.h>
#include <stdlib.h>

struct SinglyLinkedListNode {
    int data;
    struct SinglyLinkedListNode* next;
};

void printLinkedList(struct SinglyLinkedListNode* head) {
    struct SinglyLinkedListNode* current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

struct SinglyLinkedListNode* insertNode(struct SinglyLinkedListNode* head, int data) {
    struct SinglyLinkedListNode* newNode = (struct SinglyLinkedListNode*)malloc(sizeof(struct SinglyLinkedListNode));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct SinglyLinkedListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head;
}

int main() {
    int n, i, value;
    struct SinglyLinkedListNode* head = NULL;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertNode(head, value);
    }

    printLinkedList(head);

    struct SinglyLinkedListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

