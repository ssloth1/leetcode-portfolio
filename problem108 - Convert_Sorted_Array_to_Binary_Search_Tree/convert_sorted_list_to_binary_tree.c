// Leetcode Problem: 108. Convert Sorted Array to Binary Search Tree - https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// James Bebarski - Submission
// Easy Difficulty
// Tree Tag

#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    
    // If the given numsSize is 0 or less, return null. 
    if (numsSize <= 0) {
        return NULL;
    }

    int mid = numsSize / 2; // Get the location of the middle element by dividing the given size by 2. 
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode)); // Allocate memory for a new TreeNode to store the root.
    root->val = nums[mid]; // Assigns the value of the middle element of the array to the root node. 
    // Recursively create the left subtree. 
    root->left = sortedArrayToBST(nums, mid);
    // Recursively create the right subtree. 
    root->right = sortedArrayToBST(nums + mid + 1, numsSize - mid -1);

    return root; // Return the root node of the tree. 
}

