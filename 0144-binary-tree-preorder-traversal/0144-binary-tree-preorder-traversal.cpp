/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preorder(TreeNode* node, std::vector<int>& res) {
        if (node == nullptr) {
            return;
        }
        res.push_back(node->val);
        preorder(node->left, res);
        preorder(node->right, res);
    } 
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;      
    }

    //  ========= Preorder ========
    // vector<int> preorderTraversal(TreeNode* root) {
    //     if (!root) return {}; // Return empty for an empty tree

    //     vector<int> result;
    //     stack<TreeNode*> s;
    //     s.push(root);

    //     while (!s.empty()) {
    //         TreeNode* node = s.top();
    //         s.pop();
    //         result.push_back(node->val);

    //         // Push right child first so that left child is processed first
    //         if (node->right) s.push(node->right);
    //         if (node->left) s.push(node->left);
    //     }

    //     return result;
    // }
};