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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans; // base case
        int c = 1;      // check when to reverse
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = NULL;
            int n = q.size();
            vector<int> r;
            while (n) {
                curr = q.front();
                q.pop();
                r.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                n--;
            }
            if (c % 2 == 0) {
                reverse(
                    r.begin(),
                    r.end()); // we have to print right to left at even level
            }
            ans.push_back(r);
            c++;
        }
        return ans;
    }
};