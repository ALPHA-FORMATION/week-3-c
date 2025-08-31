//Nth node from end
//https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1



#include <stdio.h>
#include <stdlib.h>

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

int kthFromEnd(struct Node* head, int k) {
    struct Node* first = head;
    struct Node* second = head;
    int i; 

    for (i = 0; i < k; i++) {
        if (first == NULL) {
            return -1; 
        }
        first = first->next;
    }

    while (first != NULL) {
        first = first->next;
        second = second->next;
    }

    return (second != NULL) ? second->data : -1;
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

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    struct Node* head1 = createLinkedList(arr1, 9);
    printf("%d\n", kthFromEnd(head1, 2)); 

    int arr2[] = {10, 5, 100, 5};
    struct Node* head2 = createLinkedList(arr2, 4);
    printf("%d\n", kthFromEnd(head2, 5)); 

    return 0;
}

