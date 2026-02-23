#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    struct ListNode* current = head;
    
    while (current != NULL) {
        if (current->val == val) {
            prev->next = current->next;
            struct ListNode* temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
    
    return dummy.next;
}
