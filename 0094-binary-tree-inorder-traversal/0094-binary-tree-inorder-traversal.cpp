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
    void inorder(TreeNode* node, vector<int>& res) {
        if (!node) {
            return;
        }
        inorder(node->left, res);
        res.push_back(node->val);
        inorder(node->right, res);
    } 
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }

    // ========= Iterative ========= 
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> result;
    //     stack<TreeNode*> s;
    //     TreeNode* curr = root;

    //     while (curr || !s.empty()) {
    //         // Traverse to the leftmost node
    //         while (curr) {
    //             s.push(curr);
    //             curr = curr->left;
    //         }
    //         // Process the top node
    //         curr = s.top();
    //         s.pop();
    //         result.push_back(curr->val);

    //         // Visit the right subtree
    //         curr = curr->right;
    //     }

    //     return result;
    // }
};