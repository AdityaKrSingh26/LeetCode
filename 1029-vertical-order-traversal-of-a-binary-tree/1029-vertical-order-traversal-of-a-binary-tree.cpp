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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        // Map structure: {HD -> {VL -> {nodes at this position}}}
        map<int, map<int, multiset<int>>> nodes;

        // Queue for BFS traversal: {node, {HD, VL}}
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});

        while (!todo.empty()) {
            auto it = todo.front();
            todo.pop();

            TreeNode* node = it.first;
            int hd = it.second.first;  // Horizontal Distance
            int vl = it.second.second; // Vertical Level

            // Insert node into map
            nodes[hd][vl].insert(node->val);

            // Left child (HD - 1, VL + 1)
            if (node->left) {
                todo.push({node->left, {hd - 1, vl + 1}});
            }

            // Right child (HD + 1, VL + 1)
            if (node->right) {
                todo.push({node->right, {hd + 1, vl + 1}});
            }
        }

        // Extracting values from map and pushing into ans
        for (auto& hd_map : nodes) {
            vector<int> col;
            for (auto& vl_map : hd_map.second) {
                col.insert(col.end(), vl_map.second.begin(), vl_map.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};