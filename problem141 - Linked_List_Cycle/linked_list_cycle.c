// Leetcode Problem: 141. Linked List Cycle - https://leetcode.com/problems/linked-list-cycle/
// James Bebarski - Submission
// Easy Difficulty
// Tree Tag

//Definition for singly-linked list - provided by leetcode.
struct ListNode {
  int val;
  struct ListNode *next;
};


// Recursive helper function to check if there is a cycle in the linked list.
bool hasCycleHelper(struct ListNode *current, struct ListNode *next) {
    
    // Check if either the next node or the node after that is NULL.
    if (next == NULL || next->next == NULL) {
        return false;
    }
    
    // Check if the current node and the next node are the same. 
    if (current == next) {
        return true;
    }

    // Check if the current node and the node two positions ahead are the same. 
    if (current == next->next) {
        return true;
    }

    // Recursively call the helper funtion with the next node and the node two positions ahead. 
    return hasCycleHelper(current->next, next->next->next);
}

// Checks if a cycle exists in a linked list.
bool hasCycle(struct ListNode *head) {
    // Check if the head pointer is null. 
    if (head == NULL) {
        return false;
    }
    // Call the helper function with the head node and the next node as arguments. 
    return hasCycleHelper(head, head->next);
}