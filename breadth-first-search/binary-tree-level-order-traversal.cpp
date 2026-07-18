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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans; // to store ans
        if (root == NULL)
            return ans; // if no root
        queue<TreeNode*> q;
        q.push(root); // pushed root
        while (!q.empty()) {
            vector<int> r;
            TreeNode* curr = NULL;
            int n = q.size(); // queue size
            while (n) {
                curr = q.front();
                q.pop();
                r.push_back(curr->val); // adding level wise values to r
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                n--;
            }
            ans.push_back(r); // pushing vector r into ans
        }
        return ans;
    }
};