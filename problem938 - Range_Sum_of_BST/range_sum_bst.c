// Leetcode Problem: 938. Range Sum of BST - https://leetcode.com/problems/range-sum-of-bst/
// James Bebarski - Submission
// Easy Difficulty
// Trees/BinaryTrees

// Definition for a binary tree node - provided by leetcode.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int rangeSumBST(struct TreeNode* root, int low, int high){
    // If given root is NULL return 0.
    if (root == NULL) {
        return 0;
    }
    
    if (root->val < low) {
        // If the given root is less than the provided lower bound, we need to traverse the right subtree.
        return rangeSumBST(root->right, low, high);
    } else if (root->val > high) {
        // If the given root value is greater than the provided upper bound, we need to traverse the left subtree.
        return rangeSumBST(root->left, low, high);
    } else {
        // The node value must be within range, so we add it its value and recursively search both subtrees.
        return rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high) + root->val;
    }
}
