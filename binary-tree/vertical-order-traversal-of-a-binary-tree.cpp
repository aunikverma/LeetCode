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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == NULL) {
            return ans; // base case
        }
        map<int, map<int, multiset<int>>> nodes;  // hd,{level,values}
        queue<pair<TreeNode*, pair<int, int>>> q; // node*,{hd,level}
        q.push({root, {0, 0}});                   // root ,{0,0}
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            TreeNode* curr = temp.first;    // curr
            int hd = temp.second.first;     // horizontal distance
            int level = temp.second.second; // level

            nodes[hd][level].insert(curr->val); // level wise and hd wise value
            // if left not null
            if (curr->left)
                q.push({curr->left, {hd - 1, level + 1}});
            // if right not null
            if (curr->right)
                q.push({curr->right, {hd + 1, level + 1}});
        }
        for (auto i : nodes) {
            vector<int> col; // temporary vector
            for (auto j : i.second) {
                for (auto k : j.second) {
                    col.push_back(k);
                }
            }
            ans.push_back(col);
        }
        return ans;
    }
};