// Leetcode Problem: 104. Maximum Depth of Binary Tree - https://leetcode.com/problems/maximum-depth-of-binary-tree/
// James Bebarski - Submission
// Easy Difficulty
// Tree Tag

// Definition for a binary tree node - provided by leetcode
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root){
    
    // If the tree is empty we say the depth is 0. 
    if (root == NULL) {
        return 0;
    }

    // Calculates the depth of the left and right subtrees recursively.
    int leftSubtreeDepth = maxDepth(root->left) + 1;
    int rightSubtreeDepth = maxDepth(root->right) + 1;

    // Compare the calculated depths and return the deepest value. 
    // If they are the same depth it doesn't matter which variable we return, the value is the same.
    if (leftSubtreeDepth >= rightSubtreeDepth) {
        return leftSubtreeDepth;
    }
    
    // If the right subtree has a greater depth than the left.
    if (rightSubtreeDepth > leftSubtreeDepth) {
        return rightSubtreeDepth;
    }
    return 0; 
}