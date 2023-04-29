// Leetcode Problem: 100. Same Tree - https://leetcode.com/problems/same-tree/
// James Bebarski - Submission
// Easy Difficulty
// Tree Tag


// Definition for a binary tree node. - provided by leetcode.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    
    // First we should check if they are both null, if so they are the same. 
    if (p == NULL && q == NULL) {
        return true;
    } 

   // If one of the trees is empty while the other is not, the they are not the same.
    if (p == NULL || q == NULL) {
        return false; 
    }

    // If the values of the nodes are the same, we need to check the left and right subtrees. 
    if (p->val == q->val) {
        // Recursively check the left and right subtrees.
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    } else {
        return false; 
    }
}