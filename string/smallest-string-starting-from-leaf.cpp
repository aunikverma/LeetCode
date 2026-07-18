
class Solution {
private:
    void findPaths(TreeNode* root, string& s, vector<string>& ans) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            s += 'a' + root->val;
            ans.push_back(s);
            s.pop_back();
            return;
        }
        s += 'a' + root->val;
        findPaths(root->left, s, ans);
        findPaths(root->right, s, ans);
        s.pop_back();
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        vector<string> ans;
        string s = "";
        findPaths(root, s, ans);
        for (int i = 0; i < ans.size(); i++) {
            reverse(ans[i].begin(), ans[i].end());
        }
        sort(ans.begin(), ans.end());
        return ans[0];
    }
};