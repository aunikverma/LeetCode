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
    void inorder(TreeNode* root, vector<int>& r) {
        if (!root)
            return;
        inorder(root->left, r);
        r.push_back(root->val);
        inorder(root->right, r);
    }

public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> r;
        inorder(root, r);
        vector<vector<int>> ans;
        for (int i : queries) {
            auto x = lower_bound(begin(r), end(r), i); //first element in r ≥ i.
            int mini = -1, maxi = -1; //If none found returns r.end().
            if (x != r.end()) {
                maxi = *x; //smallest values r >= i
            }
            if (x != r.end() && *x == i) {
                mini = maxi;// If value present both mini & maxi are same
            } else if (x != r.begin()) {//Otherwise closest smaller is element before x
                mini = *(prev(x));// prev(x) gives the element just smaller than i
            }
            ans.push_back({mini, maxi});
        }
        return ans;
    }
};