class Solution {
private:
    void solve(TreeNode* root, int& ans, string& path) {
        if (!root) { //not root
            return;
        }
        if (!root->left && !root->right) { //when leaf node
            path += to_string(root->val);
            ans += stoi(path);
            path.pop_back(); //bactrack
            return;
        }
        path += to_string(root->val); //add
        solve(root->left, ans, path);
        solve(root->right, ans, path);
        path.pop_back(); //backtrack
    }

public:
    int sumNumbers(TreeNode* root) {
        string path = "";
        int ans = 0;
        solve(root, ans, path);
        return ans;
    }
};