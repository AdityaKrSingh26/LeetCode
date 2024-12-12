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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
            return new TreeNode(val);
        TreeNode* curr = root;
        while (curr) {
            if (val < curr->val) {
                if (curr->left == nullptr) {
                    TreeNode* node = new TreeNode(val);
                    curr->left = node;
                    break;
                } else {
                    curr = curr->left;
                }
            } else if (val > curr->val) {
                if (curr->right == nullptr) {
                    TreeNode* node = new TreeNode(val);
                    curr->right = node;
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }
        return root;
    }
};