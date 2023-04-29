// Leetcode Problem: 206. Reverse Linked List - https://leetcode.com/problems/reverse-linked-list/
// James Bebarski - Submission
// Easy Difficulty
// Linked List Tag

//Definition for singly-linked list - provided by leetcode.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head){
    // Checks if the given list is empty, if so there's nothing to reverse.
    if (head == NULL) {
        return head;
    }
    // Checks if the head pointer points to the last node, if so there's nothing to reverse.
    if (head->next == NULL) {
        return head;
    }

    // Recursively reverse the sublist starting from the second node.
    struct ListNode *newHead = reverseList(head->next);
    
    // Update the pointers to reverse the direction of the current node.
    head->next->next = head;
    head->next = NULL;

    // Return the new head of our reversed linked list. 
    return newHead;

}