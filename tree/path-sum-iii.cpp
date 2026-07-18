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
private:
    void solve(TreeNode* root, int t, int& count, vector<int> path) {
        if (root == NULL) {
            return; // base case
        }

        path.push_back(root->val); // added the element

        solve(root->left, t, count, path);  // left
        solve(root->right, t, count, path); // right

        // check for count
        long long sum = 0;
        for (int i = path.size() - 1; i >= 0; i--) {
            sum += path[i];
            if (sum == t) {
                count++;
            }
        }

        // backtrack
        path.pop_back();
    }

public:
    int pathSum(TreeNode* root, int t) {
        vector<int> path;
        int count = 0;
        solve(root, t, count, path);
        return count;
    }
};