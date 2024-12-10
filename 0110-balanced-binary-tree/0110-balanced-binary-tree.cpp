/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int checkHeight(TreeNode* root) {
        if (!root)
            return 0;
        int leftHeight = checkHeight(root->left);
        int rightHeight = checkHeight(root->right);
        if (leftHeight == -1 || rightHeight == -1)
            return -1;
        if (abs(leftHeight - rightHeight) > 1)
            return -1; 
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) { 
        return checkHeight(root) != -1; 
    }

    // ====== Brute Force ====
    // int maxDepth(TreeNode* root) {
    //     if (!root)
    //         return 0;
    //     int l = maxDepth(root->left);
    //     int r = maxDepth(root->right);
    //     return (1 + max(l, r));
    // }
    // bool isBalanced(TreeNode* root) {
    //     if (!root)
    //         return true;
    //     int left = maxDepth(root->left);
    //     int right = maxDepth(root->right);
    //     cout << left - right << endl;
    //     if (abs(left - right) <= 1 && isBalanced(root->left) &&
    //         isBalanced(root->right)) {
    //         return true;
    //     }
    //     return false;
    // }
};