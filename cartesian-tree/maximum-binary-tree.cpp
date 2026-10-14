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
    TreeNode* buildTree(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        int maxi = INT_MIN;
        int pos = -1;
        for (int i = start; i <= end; i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                pos = i;
            }
        }
        TreeNode* root = new TreeNode(maxi);
        root->left = buildTree(nums, start, pos - 1);
        root->right = buildTree(nums, pos + 1, end);
        return root;
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
};