/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // If both nodes are NULL, trees are same
    if (p == NULL && q == NULL) {
        return true;
    }
    
    // If one is NULL and other is not, trees are different
    if (p == NULL || q == NULL) {
        return false;
    }
    
    // Check current node values and recursively check left and right subtrees
    return (p->val == q->val) &&
           isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}