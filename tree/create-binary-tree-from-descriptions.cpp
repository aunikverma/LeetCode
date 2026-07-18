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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, pair<int, TreeNode*>> mp;
        for (auto& i : descriptions) {
            int p_val = i[0], c_val = i[1], isleft = i[2];

            // parent
            TreeNode* parent = NULL;
            if (mp.find(p_val) == mp.end()) {
                parent = new TreeNode(p_val);
                mp[p_val] = {-1, parent};
            } else {
                parent = mp[p_val].second;
            }

            // child
            TreeNode* child = NULL;
            if (mp.find(c_val) == mp.end()) {
                child = new TreeNode(c_val);
            } else {
                child = mp[c_val].second;
            }
            // assign parent
            mp[c_val] = {p_val, child};

            // assign child
            if (isleft) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }

        TreeNode* root = NULL;
        for (auto& v : mp) {
            if (v.second.first == -1) {
                root = v.second.second;
                break;
            }
        }
        return root;
    }
};