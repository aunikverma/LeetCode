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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& preindex,
                    int instart, int inend, unordered_map<int, int>& mp) {
        // base case
        if (preindex > inorder.size() || instart > inend) {
            return NULL; // out of bound
        }

        int element = preorder[preindex++]; // curr root element

        TreeNode* root = new TreeNode(element); // making new node

        int pos = mp[element]; // pos of element from inorder

        // recursion

        root->left = solve(preorder, inorder, preindex, instart, pos - 1, mp);

        root->right = solve(preorder, inorder, preindex, pos + 1, inend, mp);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex = 0; // preorder root start
        int n = inorder.size();
        // creating map to find inorder pos index
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        // preorder vec,inorder vec,preorder index,instart,inend,mapping of
        // index of inorder
        TreeNode* ans = solve(preorder, inorder, preindex, 0, n - 1, mp);
        return ans;
    }
};