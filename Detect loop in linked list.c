//Detect loop in linked list
//https://www.geeksforgeeks.org/problems/detect-loop-in-linked-list/1



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

bool hasLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;           
        fast = fast->next->next;     
        if (slow == fast) {
            return true; 
        }
    }
    return false; 
}

struct Node* createLinkedList(int arr[], int n) {
    if (n == 0) return NULL;
    struct Node* head = createNode(arr[0]);
    struct Node* current = head;
    int i;
    for (i = 1; i < n; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

void createLoop(struct Node* head, int pos) {
    if (pos == 0) return; 

    struct Node* loopNode = head;
    int count = 1;
    while (count < pos && loopNode != NULL) {
        loopNode = loopNode->next;
        count++;
    }

    struct Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    tail->next = loopNode; 
}

int main() {
    int arr1[] = {1, 3, 4};
    struct Node* head1 = createLinkedList(arr1, 3);
    createLoop(head1, 2);
    printf("%s\n", hasLoop(head1) ? "true" : "false"); 

    int arr2[] = {1, 8, 3, 4};
    struct Node* head2 = createLinkedList(arr2, 4);
    createLoop(head2, 0);
    printf("%s\n", hasLoop(head2) ? "true" : "false"); 

    int arr3[] = {1, 2, 3, 4};
    struct Node* head3 = createLinkedList(arr3, 4);
    createLoop(head3, 1);
    printf("%s\n", hasLoop(head3) ? "true" : "false"); 

    return 0;
}

