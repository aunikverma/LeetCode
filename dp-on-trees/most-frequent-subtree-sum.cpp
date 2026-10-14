class Solution {
private:
    int solve(TreeNode* root, unordered_map<int, int>& mp) {
        if (!root) {
            return 0;
        }
        if (!root->left && !root->right) { // if leaf node sum is root->val
            mp[root->val]++;
            return (root->val);
        }
        int lefty = solve(root->left, mp);
        int righty = solve(root->right, mp);
        int sum = root->val + lefty + righty; // storing root sum
        mp[sum]++;
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mp;
        int a = solve(root, mp);
        int max_f = 0;
        for (auto& v : mp) { // storing sums in mp
            max_f = max(max_f, v.second);
        }
        vector<int> ans;
        for (auto& v : mp) { // returning elemens having maximum frequency
            if (v.second == max_f) {
                ans.push_back(v.first);
            }
        }
        return ans;
    }
};