//Add two numbers represented by linked lists
//https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1



#include <stdio.h>
#include <stdlib.h>

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

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct Node* addTwoLists(struct Node* head1, struct Node* head2) {
    head1 = reverseList(head1);
    head2 = reverseList(head2);

    struct Node* result = NULL;
    struct Node* tail = NULL;
    int carry = 0;

    while (head1 != NULL || head2 != NULL || carry) {
        int sum = carry;
        if (head1) {
            sum += head1->data;
            head1 = head1->next;
        }
        if (head2) {
            sum += head2->data;
            head2 = head2->next;
        }
        carry = sum / 10;
        sum = sum % 10;

        struct Node* temp = newNode(sum);
        if (result == NULL) {
            result = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    result = reverseList(result);

    while (result != NULL && result->data == 0 && result->next != NULL) {
        struct Node* temp = result;
        result = result->next;
        free(temp);
    }

    return result;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head1 = newNode(4);
    head1->next = newNode(5);

    struct Node* head2 = newNode(3);
    head2->next = newNode(4);
    head2->next->next = newNode(5);

    struct Node* result = addTwoLists(head1, head2);
    printList(result); 

    struct Node* h1 = newNode(0);
    h1->next = newNode(0);
    h1->next->next = newNode(6);
    h1->next->next->next = newNode(3);

    struct Node* h2 = newNode(0);
    h2->next = newNode(7);

    struct Node* result2 = addTwoLists(h1, h2);
    printList(result2); 

    return 0;
}

