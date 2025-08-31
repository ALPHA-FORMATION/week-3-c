//Search in linked list
//https://www.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

bool searchKey(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key)
            return true;
        current = current->next;
    }
    return false;
}

int main() {
    int n, key, i, val;
    struct Node* head = NULL;
    struct Node* temp = NULL;

    scanf("%d %d", &n, &key);

    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* new_node = newNode(val);
        if (head == NULL) {
            head = new_node;
            temp = head;
        } else {
            temp->next = new_node;
            temp = temp->next;
        }
    }

    if (searchKey(head, key))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}

