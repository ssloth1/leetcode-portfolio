// Leetcode Problem: 21. Merge Two Sorted Lists - https://leetcode.com/problems/merge-two-sorted-lists/
// James Bebarski - Submission
// Easy Difficulty
// Linked List Tag

#include <stdlib.h> // Included by myself.

// Definition for singly-linked list - provided by leetcode.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    
    // If list one is empty, return list 2.
    if (list1 == NULL)
        return list2;

    // If list 2 is empty, return list 1.
    if (list2 == NULL)
        return list1;
    
    // If the value of the first node of list 1 is smaller or equal to the value of the first node of list2,
    // list1 should come first in the merged list
    if (list1->val <= list2->val) {
        // Merge the remaining nodes of list1 with list2 and update the next pointer of list1.
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;

    } else {
        // Merge the remaining nodes of list2 with list1 and update the next pointer of list2.
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
    
}