// Leetcode Problem: 700. Search in a Binary Search Tree - https://leetcode.com/problems/search-in-a-binary-search-tree/
// James Bebarski - Submission
// Easy Difficulty
// Binary Tree Tag

#include <stdlib.h>

// Definition for a binary tree node - provided by leetcode.
struct TreeNode {
    int val;
    struct TreeNode *left;
  struct TreeNode *right;
};
 
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    // Check to see if a valid tree was given.
    if (root == NULL) {
        return root;
    }
    // If the root's value is equal to the target value, return the root. 
    if (root->val == val) {
        return root;
    }
    // If the target value is smaller than the root's value,search in the left subtree.  
    if (val < root->val) {
        return searchBST(root->left, val);
    } else {
        // The target value is greater than the root's value, so we search in the right subtree.
        return searchBST(root->right, val);
    }
}