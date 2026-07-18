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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root); // using bfs store level wise elements in queue
        while (!q.empty()) {
            TreeNode* curr = NULL;
            int c = q.size();
            int n = q.size();
            double d = 0;
            while (n) {
                curr = q.front(); // add level sum in d
                q.pop();
                d += (curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                n--;
            }
            ans.push_back(d / c * 1.0); // add average to the ans
        }
        return ans;
    }
};