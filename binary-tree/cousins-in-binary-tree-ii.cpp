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
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root) {
            root->val = 0; // base case
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int sum = 0;
            vector<TreeNode*> a;
            while (n) {
                TreeNode* curr = q.front(); //collect all nodes and take sum of all children at a level
                q.pop();
                a.push_back(curr);
                if (curr->left) {
                    q.push(curr->left);
                    sum += curr->left->val;
                }
                if (curr->right) {
                    q.push(curr->right);
                    sum += curr->right->val;
                }
                n--;
            }
            for (auto& i : a) {
                int t = sum; //again initialize for left and right respectively
                if (i->left) //delete its own children values from sum and put it into the place
                    t -= i->left->val;
                if (i->right)
                    t -= i->right->val;
                if (i->left)
                    i->left->val = t;
                if (i->right)
                    i->right->val = t;
            }
        }
        return root;
    }
};