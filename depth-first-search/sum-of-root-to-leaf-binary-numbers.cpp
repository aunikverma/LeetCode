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
    int decimal(string& s) {
        int a = 0;
        int c = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            a += ((1 << c) * (s[i] - '0'));
            c++;
        }
        return a;
    }

    void findPaths(TreeNode* root, string& s, int& sum) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            s += to_string(root->val);
            sum += decimal(s);
            s.pop_back();
            return;
        }
        s += to_string(root->val);
        findPaths(root->left, s, sum);
        findPaths(root->right, s, sum);
        s.pop_back();
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        string s = "";
        int sum = 0;
        findPaths(root, s, sum);
        return sum;
    }
};