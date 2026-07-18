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
    pair<bool, int> balanced(TreeNode* root) {
        if (root == NULL) {
            pair<bool, int> ans(true, 0);
            return ans; //if root is null
        }

        pair<bool, int> lefty = balanced(root->left); //go in left
        pair<bool, int> righty = balanced(root->right);//go in right

        bool l = lefty.first; 
        bool r = righty.first;
        bool diff = abs(lefty.second - righty.second) <= 1;

        pair<bool, int> ans;
        ans.second = max(lefty.second, righty.second) + 1;//height
        ans.first = (l && r && diff) ? true : false;//if all true then true
        return ans;
    }

public:
    bool isBalanced(TreeNode* root) { 
        return balanced(root).first;
        }
};