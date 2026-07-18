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
    TreeNode* recoverFromPreorder(string s) {
        vector<pair<int, int>> pq; // storing depth and value of node
        int i = 0;
        while (i < s.length()) {
            int d = 0; // depth
            while (i < s.length() && s[i] == '-') {
                d++;
                i++;
            }
            int num = 0;
            while (i < s.length() && s[i] != '-') {
                num = num * 10 + (s[i] - '0'); // 11  = 10 + 1
                i++;
            }
            pq.push_back({d, num});
        }
        // Step 2: Build tree using stack
        stack<TreeNode*> st;
        TreeNode* root = new TreeNode(pq[0].second);
        st.push(root);
        for (int i = 1; i < pq.size(); i++) {
            int depth = pq[i].first;
            int val = pq[i].second;
            TreeNode* node = new TreeNode(val);
            // Maintain stack depth
            while (st.size() > depth) { //when stack size is greater find correct parent
                st.pop(); //pop till correct parent
            }
            // Attach node as left or right child
            if (!st.top()->left) { //if loft not null
                st.top()->left = node;
            } else {
                st.top()->right = node; //or if right not null
            }
            st.push(node);
        }
        return root;
    }
};

// Start with root → push it in stack.

// For each new node:

// If stack size > depth → pop until size = depth (go back to correct parent).

// The parent is now st.top().

// If parent has no left → attach as left child. Else → attach as right child.

// Push this node into stack.