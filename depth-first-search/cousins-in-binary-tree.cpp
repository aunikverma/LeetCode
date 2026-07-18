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
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int, pair<int, TreeNode*>>
            mp; // value,level,parent(storing)
        queue<TreeNode*> q;
        q.push(root);
        mp[root->val] = {0, NULL};
        int k = 0;
        while (!q.empty()) {
            TreeNode* curr = NULL;
            int n = q.size();
            k++;
            while (n) {
                curr = q.front();
                q.pop();
                if (curr->left) {
                    mp[curr->left->val] = {k, curr};
                    q.push(curr->left);
                }
                if (curr->right) {
                    mp[curr->right->val] = {k, curr};
                    q.push(curr->right);
                }
                n--;
            }
        }
        auto x1 = mp[x];
        auto y1 = mp[y];
        if (x1.first == y1.first && x1.second != y1.second)
            return true; // if levels are same and parent different
        return false;
    }
};