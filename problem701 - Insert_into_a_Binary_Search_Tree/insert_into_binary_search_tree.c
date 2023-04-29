// Leetcode Problem: 701. Insert into a Binary Search Tree - https://leetcode.com/problems/insert-into-a-binary-search-tree/
// James Bebarski - Submission
// Medium Difficulty
// Binary Tree

#include <stdlib.h>

// Definition for a binary tree node - Provided by leetcode.
struct TreeNode {
   int val;
   struct TreeNode *left;
   struct TreeNode *right;
};

// Recursive approach to BST insertion. 
struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    // If the tree is empty, create a new node with the given value.
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    } else {
        // Compare the value to be inserted with the value at the root node.
        if (val < root->val) {
            // If the value is less than the root value, insert it in the left subtree.
            root->left = insertIntoBST(root->left, val);
        }
        if (val > root->val) {
            // If the value is greater than the root value, insert it in the right subtree.
            root->right = insertIntoBST(root->right, val);
        }
        // Return the root node of the updated tree. 
        return root;
    }
}