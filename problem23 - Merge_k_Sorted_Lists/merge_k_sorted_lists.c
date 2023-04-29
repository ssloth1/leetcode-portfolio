// Leetcode Problem: 23. Merge k Sorted Lists - https://leetcode.com/problems/merge-k-sorted-lists/
// James Bebarski - Submission
// Hard Difficulty
// Linked List, Divide and Conquer, Merge Sort Tags


//Definition for singly-linked list - provided by leetcode.
struct ListNode {
    int val;
    struct ListNode *next;
};


// Merge two sorted linked lists into a single sorted linked list
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    // If list 1 is empty, return list 2. 
    if (l1 == NULL) {
        return l2;
    }
    // If list 2 is empty, return list 1. 
    if (l2 == NULL) {
        return l1;
    }
    
    // Determine which node has the smaller value and set it's next pointer to the result 
    // of recursively merging the remaining nodes.
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

// Merge an array of k sorted linked lists into a single sorted linked list.
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    // If there are no lists, return null.
    if (listsSize == 0) {
        return NULL;
    }
    // If there's only one list, return it. 
    if (listsSize == 1) {
        return lists[0];
    }

    // Divide the array into two halves, recursively merge each half, and then merge the resulting two halves.
    int midPoint = listsSize / 2;
    struct ListNode* left = mergeKLists(lists, midPoint);
    struct ListNode* right = mergeKLists(lists + midPoint, listsSize - midPoint);
    return mergeTwoLists(left, right);
}