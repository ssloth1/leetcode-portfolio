// Leetcode Problem: 235. Lowest Common Ancestor of a Binary Search Tree - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// James Bebarski - Submission
// Medium Difficulty
// Binary Search Tree Tag

#include <stdlib.h>

//Definition for a binary tree node - provided by leetcode.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {

    // If the given root is NULL, the LCA does not exist. 
    if (root == NULL) {
        return NULL;
    }
    // If either p or q is null, the LCA does not exist.
    if (p == NULL || q == NULL) {
        return NULL;
    }

    // If both p and q are smaller than the root, the LCA lies within the left subtree.
    if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    // If both p and q are greater than the root, the LCA lies within the right subtree.
    } else if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    // If the root lies between p and q, it must be the be the LCA.
    } else {
        return root;
    }
}