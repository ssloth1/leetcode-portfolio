// Leetcode Problem: 83. Remove Duplicates From Sorted List - https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// James Bebarski - Submission
// Easy Difficulty
// Tree Tag
// Linked List Tag

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    
    // Check if the list is empty.
    if (head == NULL) {
        return head;
    }

    // Check if the list only contains one node. 
    if (head->next == NULL) {
        return head;
    }

    // Recursively remove duplicates from the rest of the list.
    head->next = deleteDuplicates(head->next);

    // Checks if the current node is a duplicate of the next node.
    if (head->val == head->next->val) {
        // If so, remove the next node and update the current node's next pointer.
        struct ListNode* temp = head->next; // Saves the pointer to the node to be removed.
        head->next = temp->next; // Update the next pointer of the current node to skip over the removed node.
        free(temp); // Free the memory used by the removed node.
    }
    return head; // Return the head of our trimmed up linked list.
}