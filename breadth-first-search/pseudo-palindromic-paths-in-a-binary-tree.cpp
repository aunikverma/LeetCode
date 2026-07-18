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
    // private: //this is taking too much time
    //     void getPaths(TreeNode* root, vector<string>& ans, string& path) {
    //         if (!root) return;
    //         int len = path.size(); //taking size because root->val can be
    //         greater than 10 path += to_string(root->val); if (!root->left &&
    //         !root->right) {
    //             ans.push_back(path);
    //         } else {
    //             getPaths(root->left, ans, path);
    //             getPaths(root->right, ans, path);
    //         }
    //         path.resize(len); //and pop_back will only remove one character
    //         ie using resize
    //     }

    //     bool check(string& s) {
    //         unordered_map<char, int> mp;
    //         for (char c : s) {
    //             mp[c]++;
    //         }
    //         int odd = 0;
    //         for (auto& v : mp) {
    //             if (v.second % 2 == 1) {
    //                 odd++;
    //                 if (odd > 1) return false;
    //             }
    //         }
    //         return true;
    //     }

    // public:
    //     int pseudoPalindromicPaths(TreeNode* root) {
    //         vector<string> ans;
    //         string path = "";
    //         getPaths(root, ans, path);
    //         int count = 0;
    //         for (auto& i : ans) {
    //             if (check(i)) count++;
    //         }
    //         return count;
    //     }
    // };

private:
    int dfs(TreeNode* node, int mask) {
        if (!node) return 0;

        // Toggle the bit for current node's value
        mask ^= (1 << node->val); // mask = 000000 and mask ^= (1 << 2),mask =
                                  // 000100 2nd bit will set to ~(bit)
        // if 0 -> 1 and 1 -> 0

        // If leaf, check the mask
        if (!node->left && !node->right) {
            // If mask has at most one bit set, it's pseudo-palindromic
            if ((mask & (mask - 1)) == 0) return 1; // onyl 1 set bit then true
            else return 0;
        }

        // Otherwise, keep traversing
        return dfs(node->left, mask) + dfs(node->right, mask);
    }

public:
    int pseudoPalindromicPaths(TreeNode* root) { return dfs(root, 0); }
};