class Solution {
private:
    void solve(TreeNode* root, int targetsum, vector<int>& A,
               vector<vector<int>>& ans) {

        if (root == NULL) {
            return; // if root is NULL
        }

        A.push_back(root->val); // wrna A me root->val dal do
        targetsum -= root->val; // target sum me se subtract call

        if (root->left == NULL && root->right == NULL) { // if root is leaf node
            if (targetsum == 0) {
                ans.push_back(A); // ans found
            }
        }

        solve(root->left, targetsum, A, ans);  // left call
        solve(root->right, targetsum, A, ans); // right call

        A.pop_back(); // backtrack ensure path maintained
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetsum) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }

        vector<int> A;

        solve(root, targetsum, A, ans);

        return ans;
    }
};