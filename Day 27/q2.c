#include <stdio.h>
#include <stdlib.h>
#include 

struct Node {
    int data;
    struct Node* next;
};

void removeLoop(struct Node* head) {
    if (head == NULL || head->next == NULL) return;
    
    struct Node* slow = head;
    struct Node* fast = head;
    
    // Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    
    if (slow != fast) return; // No cycle
    
    // Find start of cycle
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    
    // Remove cycle
    fast->next = NULL;
}
