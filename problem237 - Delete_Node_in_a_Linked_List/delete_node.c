// Leetcode Problem: 237. Delete Node in a Linked List - https://leetcode.com/problems/delete-node-in-a-linked-list/
// James Bebarski - Submission
// Medium Difficulty
// Linked List


// Definition for singly-linked list - provided by leetcode.
struct ListNode {
    int val;
    struct ListNode *next;
};

void deleteNode(struct ListNode* node) {
    
    // If the given node is NULL, there's nothing to delete.
    if (node == NULL) {
        return; 
    }
    // Get a reference the next node.
    struct ListNode* nextNode = node->next;

    // If the next node is null, the given node is the tail. 
    // Since one of the constraints is "The node to be deleted is in the list and is not a tail node."
    // We do not continue. 
    if (nextNode == NULL) {
        return;
    }

    node->val = nextNode->val; // Copy the value of the next node to the current node. 
    node->next = nextNode->next; // Update the current node's next pointer to skip the next node.

    free(nextNode); //Although the node is now skipped over, we need to free the memory.
}