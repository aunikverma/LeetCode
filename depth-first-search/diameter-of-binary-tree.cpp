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
    pair<int, int> diameterfast(TreeNode* root) {
        if (root == NULL) {
            pair<int, int> ans(0, 0); // first : diameter,second : height
            return ans;
        }

        pair<int, int> lefty = diameterfast(root->left);
        pair<int, int> righty = diameterfast(root->right);

        // left
        int a = lefty.first;
        // right
        int b = righty.first;
        // combo
        int c = lefty.second + righty.second; // no of edges

        pair<int, int> ans;
        ans.first = max(a, max(b, c));
        ans.second = max(lefty.second, righty.second) + 1;
        return ans;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int>ans = diameterfast(root); // diameter
        cout << ans.second;
        return ans.first;
    }
};