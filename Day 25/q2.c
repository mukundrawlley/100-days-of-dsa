struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    // Step 1: Detect cycle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }

    // No cycle
    if (fast == NULL || fast->next == NULL) return NULL;

    // Step 2: Find cycle start
    while (head != slow) {
        head = head->next;
        slow = slow->next;
    }

    return head; // Start of the cycle
}
