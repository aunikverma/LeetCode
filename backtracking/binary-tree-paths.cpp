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
// class Solution {
// private:
//     void solve(TreeNode* root, string path, vector<string>& ans) {
//         if (root == NULL) return;
//         path += to_string(root->val); // root val add
//         if (root->left == NULL && root->right == NULL) // if leaf node add to
//         ans
//         {
//             ans.push_back(path);
//             return;
//         }
//         path += "->";
//         solve(root->left, path, ans);
//         solve(root->right, path, ans);
//     }
//---------------------------------------------------------
class Solution { // using backtracking as reference(better memory usage)
private:
    void solve(TreeNode* root, string& path, vector<string>& ans) {
        if (root == NULL)
            return;
        int len = path.length();
        path += to_string(root->val); // root val add
        if (root->left == NULL &&
            root->right == NULL) // if leaf node add to ans
        {
            ans.push_back(path);
        } else {
            path += "->";
            solve(root->left, path, ans);
            solve(root->right, path, ans);
        }
        path.resize(len);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = "";
        solve(root, path, ans);
        return ans;
    }
};