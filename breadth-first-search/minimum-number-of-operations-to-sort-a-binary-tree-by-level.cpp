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
    int countSwaps(vector<int>& r) { // min swaps to sort array
        vector<int> a(r.begin(), r.end());
        unordered_map<int, int> mp;
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); i++) {
            mp[a[i]] = i; // sorted array with index
        }
        int count = 0;
        for (int i = 0; i < r.size(); i++) {
            while (mp[r[i]] != i) {
                swap(r[i], r[mp[r[i]]]);
                count++;
            }
        }
        return count;
    }

public:
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            TreeNode* curr = NULL;
            vector<int> r;
            while (n) {
                curr = q.front();
                q.pop();
                r.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                n--;
            }
            ans += countSwaps(r);
        }
        return ans;
    }
};