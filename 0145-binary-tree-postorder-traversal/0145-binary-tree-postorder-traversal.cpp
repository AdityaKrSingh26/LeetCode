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
    void dfs(TreeNode* node, vector<int>& result) {
        if (!node)
            return;
        dfs(node->left, result);     // Traverse left subtree
        dfs(node->right, result);    // Traverse right subtree
        result.push_back(node->val); // Visit root
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }

    // ----- Iterative ------
    // vector<int> postorderTraversal(TreeNode* root) {
    //     if (!root) return {}; // Return empty vector for an empty tree

    //     vector<int> result;
    //     stack<TreeNode*> stack1, stack2; // Two stacks for iterative postorder

    //     stack1.push(root);
    //     while (!stack1.empty()) {
    //         TreeNode* node = stack1.top();
    //         stack1.pop();
    //         stack2.push(node);

    //         // Push left and right children to stack1
    //         if (node->left) stack1.push(node->left);
    //         if (node->right) stack1.push(node->right);
    //     }

    //     // Stack2 contains nodes in reverse postorder
    //     while (!stack2.empty()) {
    //         result.push_back(stack2.top()->val);
    //         stack2.pop();
    //     }

    //     return result;
    // }
};